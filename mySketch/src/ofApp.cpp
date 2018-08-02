#include "ofApp.h"
#include "../../../curl/include/curl/curl.h"
#include <algorithm>
#include <string>

//--------------------------------------------------------------
// Setup method for the application to run.
void ofApp::setup(){
    // Generalized setup of the window for the application
    ofSetWindowShape(1920, 1080);
    ofSetBackgroundColor(ofColor::fromHex(0xC63240));
    ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, 0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // Set up the text input box
    text_input = new ofxDatGuiTextInput("Ticker Symbol", "MSFT");
    text_input->setTheme(new ofxDatGuiThemeSmoke());
    text_input->setWidth(800, .2);
    text_input->setPosition(0, 0);
    text_input->onTextInputEvent(this, &ofApp::onTextInputEvent);
    font.load("ofxbraitsch/fonts/Verdana.ttf", 24);
    
    // Create the vector of time series
    time_series.push_back("MONTHLY");
    time_series.push_back("DAILY");
    time_series.push_back("INTRADAY");
    
    // Create and set dropdown menu
    dropdown = new ofxDatGuiDropdown("Choose a time series", time_series);
    dropdown->setWidth(200, .2);
    dropdown->setPosition(800, 0);
    dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent);
    dropdown->setTheme(new ofxDatGuiThemeSmoke());
    
    // Create and set the calculate button
    button = new ofxDatGuiButton("GO");
    button->setWidth(100, .2);
    button->setPosition(1600, 0);
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    button->setTheme(new ofxDatGuiThemeSmoke());
    
    // Create the incorrect ticker label
    label = new ofxDatGuiLabel("Oops! Invalid Ticker Symbol.");
    label->setWidth(300, .2);
    label->setPosition(1200, 0);
    label->setTheme(new ofxDatGuiThemeSmoke());
    label_should_be_on_screen = false;
    
    // Create the x-axis scroll view
    view = new ofxDatGuiScrollView("X-Axis Legend", 16);
    view->setWidth(500);
    view->setPosition(100, 300);
    
    // Graph creation and setup
    pointColor = ofColor(255, 0, 0, 155);
    drawLines = true;
    circleResolution = 22;
    ofSetCircleResolution(circleResolution);
    plot.setPos(ofGetScreenWidth()/2, ofGetScreenHeight()/4);
    plot.setOuterDim(720, 540);
    plot.getTitle().setRelativePos(0.4);
    plot.getTitle().setTextAlignment(GRAFICA_LEFT_ALIGN);
    plot.getXAxis().setAxisLabelText("Date");
    plot.getYAxis().setAxisLabelText("Share Price ($)");
    
    // Default API variables
    time_series_string = "TIME_SERIES_MONTHLY";
    ticker = "MSFT";
    intra_offset = "60min";
    api_key = "5X9ZNHZ13S6ADV8I";
    
    // Construction of a default API request url
    api_url_vec.push_back("https://www.alphavantage.co/query?function=");
    api_url_vec.push_back(time_series_string);
    api_url_vec.push_back("&symbol=");
    api_url_vec.push_back(ticker);
    api_url_vec.push_back("&interval=");
    api_url_vec.push_back(intra_offset);
    api_url_vec.push_back("&outputsize=compact&apikey=");
    api_url_vec.push_back(api_key);
    api_url_vec.push_back("&datatype=csv");
    for (const auto &element : api_url_vec) {
        api_url += element;
    }
}

//--------------------------------------------------------------
// Updates the screen and each component based on what the user has
// input and if it is correct. Handles errors in the API URL construction
// (basically due to whether or not the user has input a valid ticker).
void ofApp::update(){
    text_input->update();
    dropdown->update();
    button->update();
    label->update();
    view->update();
    
    if (should_call_api) {
        reader.reset();
        construct_api_url();
        std::cout << api_url << "\n" << std::endl;
        std::string response = apiCall();
        should_call_api = false;
        
        if (response.c_str()[0] == '{') {
            label_should_be_on_screen = true;
        } else {
            label_should_be_on_screen = false;
            graph_should_be_on_screen = true;
            
            std::vector<std::string> vec = reader.load_csv_data(response);
            reader.create_volume_vec();
            reader.create_closing_vec();
            reader.create_date_time_vec();
            
            set_points();
            plot.activatePanning();
            plot.activateZooming(1.1, OF_MOUSE_BUTTON_LEFT, OF_MOUSE_BUTTON_LEFT);
            
            view->clear();
            for (int i = 0; i < reader.get_date_time_vec().size() - 1; i++) {
                view->add(std::to_string(i + 1) + ". " + reader.get_date_time_vec()[reader.get_date_time_vec().size() - 2 - i]);
            }
        }
    }
}

//--------------------------------------------------------------
// Draws the screen based on what the user has input and if it is correct.
void ofApp::draw(){
    text_input->draw();
    dropdown->draw();
    button->draw();
    
    if (label_should_be_on_screen) {
        label->draw();
    }
    
    if (graph_should_be_on_screen) {
        plot.beginDraw();
        plot.drawBox();
        plot.drawXAxis();
        plot.drawYAxis();
        plot.drawTitle();
        
        if (drawLines) {
            plot.drawLines();
        }
        
        plot.drawPoints(pointColor);
        plot.drawLabels();
        plot.endDraw();
        
        view->draw();
    }
}

//--------------------------------------------------------------
// Changes the ticker option that is used to construct the API URL string.
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent event) {
    ticker = event.text;
}

//--------------------------------------------------------------
// Changes the time series option that is used to construct the API URL string.
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent event) {
    if (time_series[event.child] == "DAILY") {
        time_series_string = "TIME_SERIES_DAILY";
    } else if (time_series[event.child] == "MONTHLY") {
        time_series_string = "TIME_SERIES_MONTHLY";
    } else {
        time_series_string = "TIME_SERIES_INTRADAY";
    }
}

//--------------------------------------------------------------
// Allows the application to call the API and get data.
void ofApp::onButtonEvent(ofxDatGuiButtonEvent event) {
    should_call_api = true;
}

// This function adapted from Huu Nguyen in his talk
// at CppCon 2015 about his library, Curl For People.
//--------------------------------------------------------------
// Helper function that writes API response data into API response string.
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

// This function adapted from Huu Nguyen in his talk
// at CppCon 2015 about his library, Curl For People.
// URL: https:www.youtube.com/watch?v=f_D-wD1EmWk
//--------------------------------------------------------------
// Function that uses libcurl to call the API and returns the CSV
// data in the form of a response string.
std::string apiCall() {
    auto curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
        
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;
        std::cout << response << "\n" << std::endl;
        
        return response;
    } else {
        return ""; // This is just to make sure that the method has a return statement
    }
}

//--------------------------------------------------------------
// Method to dynamically construct a URL for the API call method to use.
// Changes based on what the user inputs into the GUI.
void ofApp::construct_api_url() {
    std::transform(time_series_string.begin(), time_series_string.end(), time_series_string.begin(), ::toupper);
    std::transform(ticker.begin(), ticker.end(), ticker.begin(), ::toupper);
    
    api_url_vec[1] = time_series_string;
    api_url_vec[3] = ticker;
    api_url_vec[5] = intra_offset;
    
    if (time_series_string != "TIME_SERIES_INTRADAY") {
        api_url_vec[4] = "";
        api_url_vec[5] = "";
    } else {
        api_url_vec[4] = "&interval=";
        api_url_vec[5] = intra_offset;
    }
    
    api_url = "";
    for (const auto &element : api_url_vec) {
        api_url += element;
    }
}

//--------------------------------------------------------------
// Clears the graph and scroll view on the screen when 'c' is pressed.
void ofApp::keyPressed(int key){
    if (key == 'c') {
        graph_should_be_on_screen = false;
    }
}

//--------------------------------------------------------------
// Sets the points of the graph to the points vector using the closing price
// vector and the index associated with the date and time vector of the
// CSVReader at the time.
void ofApp::set_points() {
    points.clear();
    for (int i = 0; i < reader.get_closing_vec().size(); i++) {
        points.emplace_back(i + 1, reader.get_closing_vec()[reader.get_closing_vec().size() - 1 - i]);
    }
    
    plot.setPoints(points);
}

#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxGrafica.h"
#include "CSVReader.hpp"

// Write function for the libcurl API request declaration.
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);

// API call method declaration.
std::string apiCall();

// URL for API call that will be modified throughout program.
static std::string api_url;

class ofApp : public ofBaseApp{
    
public:
    // Open Frameworks Methods.
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    // Text input section.
    ofxDatGuiTextInput* text_input;
    ofTrueTypeFont font;
    void onTextInputEvent(ofxDatGuiTextInputEvent event);
    
    // Dropdown menu section.
    ofxDatGuiDropdown* dropdown;
    std::vector<std::string> time_series;
    void onDropdownEvent(ofxDatGuiDropdownEvent event);
    
    // "Go" button section.
    ofxDatGuiButton* button;
    void onButtonEvent(ofxDatGuiButtonEvent event);
    
    // "Incorrect" label declaration.
    ofxDatGuiLabel* label;
    
    // Data scroll view declaration.
    ofxDatGuiScrollView* view;
    
    // Graph setup section.
    ofColor pointColor;
    bool drawLines;
    int circleResolution;
    ofxGPlot plot;
    std::vector<ofxGPoint> points;
    void set_points();
    
    // API request URL variables declarations.
    std::string time_series_string;
    std::string intra_offset;
    std::string ticker;
    std::string api_key;
    std::vector<std::string> api_url_vec;
    
    // API construction method.
    void construct_api_url();
    
    // CSV reader declaration.
    CSVReader reader;
    
    // Flags for the multiple GUI components on screen.
    bool should_call_api;
    bool label_should_be_on_screen;
    bool graph_should_be_on_screen;
};

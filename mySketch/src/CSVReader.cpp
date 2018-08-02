//
//  CSVReader.cpp
//  mySketch
//
//  Created by Spencer Gilbert on 4/25/18.
//

#include "CSVReader.hpp"

//--------------------------------------------------------------
CSVReader::CSVReader() {
    // Default constructor.
}

//--------------------------------------------------------------
// Loads the CSV response string into the result vector of the class.
std::vector<std::string> CSVReader::load_csv_data(std::string response) {
    // This code adapted from Stack Overflow:
    // https:stackoverflow.com/questions/12514510/iterate-through-lines-in-a-string-c
    std::istringstream lines(response);
    std::ostringstream single_line_response;
    std::string one_line;
    
    while (getline(lines, one_line)) {
        single_line_response << one_line << ",";
    }
    
    std::istringstream modified_response(single_line_response.str());
    
    // This code adapted from Stack Overflow:
    // https:stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
    while(modified_response.good()) {
        std::string substring;
        std::getline(modified_response, substring, ',');
        result.push_back(substring);
    }
    
    return result;
}

//--------------------------------------------------------------
// Creates the closing price vector from the result vector of the class.
void CSVReader::create_closing_vec() {
    for (int i = 10; i < result.size(); i += 6) {
        closing_vec.push_back(std::stod(result[i]));
    }
}

//--------------------------------------------------------------
// Creates the volume vector from the result vector of the class.
void CSVReader::create_volume_vec() {
    for (int i = 11; i < result.size(); i += 6) {
        volume_vec.push_back(std::stol(result[i]));
    }
}

//--------------------------------------------------------------
// Creates the data and time vector from the result vector of the class.
void CSVReader::create_date_time_vec() {
    for (int i = 6; i < result.size(); i += 6) {
        date_time_vec.push_back(result[i]);
    }
}

//--------------------------------------------------------------
// Gets the closing price vector for the class.
std::vector<double> CSVReader::get_closing_vec() {
    return closing_vec;
}

//--------------------------------------------------------------
// Gets the volume vector for the class.
std::vector<long> CSVReader::get_volume_vec() {
    return volume_vec;
}

//--------------------------------------------------------------
// Gets the data and time vector of the class.
std::vector<std::string> CSVReader::get_date_time_vec() {
    return date_time_vec;
}

//--------------------------------------------------------------
// Resets all the vectors that hold data in the class.
void CSVReader::reset() {
    result.clear();
    closing_vec.clear();
    volume_vec.clear();
    date_time_vec.clear();
}

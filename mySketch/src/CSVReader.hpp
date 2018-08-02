//
//  CSVReader.hpp
//  mySketch
//
//  Created by Spencer Gilbert on 4/25/18.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

class CSVReader {
public:
    // Default constructor.
    CSVReader();
    
    // Vectors for the data being read in.
    std::vector<std::string> result;
    std::vector<double> closing_vec;
    std::vector<long> volume_vec;
    std::vector<std::string> date_time_vec;
    
    // Methods to load and create vectors for data.
    std::vector<std::string> load_csv_data(std::string response);
    void create_closing_vec();
    void create_volume_vec();
    void create_date_time_vec();
    
    // Getters for the vectors in the class.
    std::vector<double> get_closing_vec();
    std::vector<long> get_volume_vec();
    std::vector<std::string> get_date_time_vec();
    
    // Reset method for vectors.
    void reset();
};

#endif /* CSVReader_hpp */

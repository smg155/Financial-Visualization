//
//  test.cpp
//  FinalProjectTest
//
//  Created by Spencer Gilbert on 4/29/18.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/CSVReader.cpp"
#include "../../../curl/include/curl/curl.h"
#include <stdio.h>

TEST_CASE("CSV Reader Default Test") {
    CSVReader test_reader;
    SECTION("Volume Vector") {
        REQUIRE(test_reader.get_volume_vec().size() == 0);
    }
    SECTION("Closing Vector") {
        REQUIRE(test_reader.get_closing_vec().size() == 0);
    }
    SECTION("Date and Time Vector") {
        REQUIRE(test_reader.get_date_time_vec().size() == 0);
    }
}

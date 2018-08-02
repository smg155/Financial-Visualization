//
//  apiCall.cpp
//  mySketch
//
//  Created by Spencer Gilbert on 4/24/18.
//

#include "apiCall.hpp"
#include "../../../curl/include/curl/curl.h"

// This function and the libcurl request as written below adapted from Huu Nguyen
// in his talk at CppCon 2015 about his library, Curl For People.

size_t write(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

ApiRequest::ApiRequest() {
    // Default constructor!
}

std::string ApiRequest::api_call() {
    auto curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/RomelTorres/alpha_vantage");
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
    
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = NULL;
}





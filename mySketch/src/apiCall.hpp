//
//  apiCall.hpp
//  mySketch
//
//  Created by Spencer Gilbert on 4/24/18.
//

#ifndef apiCall_hpp
#define apiCall_hpp

#include <stdio.h>
#include <string>
#include <iostream>

size_t write(void *ptr, size_t size, size_t nmemb, std::string* data);

class ApiRequest {
public:
    ApiRequest();
    std::string api_call();
};

#endif /* apiCall_hpp */

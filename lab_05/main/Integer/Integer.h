#pragma once
#include "../Object/Object.h"
#include <iostream>


class Integer: public Object {
    private:
        std::map<std::string, int> data; 
    public:
        void insert(std::string key, std::string value);  
        int getValue(std::string name);
}; 
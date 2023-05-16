#pragma once 
#include "../Integer/Integer.h"

class Float: public Integer {
    private:
        std::map<std::string, double> data; 
    public:
        void insert(std::string key, std::string value);
        double getValue(std::string name);    
}; 
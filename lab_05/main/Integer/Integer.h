#pragma once
#include "../Object/Object.h"


class Integer: public Object {
    private:
        std::map<std::string, int> data; 
    public:
        void insert(std::string key, std::string value);  
        int getValue(std::string name);
        void setValue(std::string name, int value);
        bool findKey(std::string key);
}; 
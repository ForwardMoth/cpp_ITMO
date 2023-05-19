#pragma once 
#include <string> 
#include <map> 
#include <iostream>

class Object{
    public: 
        void insert(std::string key, std::string value); 
        std::string getValue(std::string name);
        bool findKey(std::string key);
    protected: 
        bool isValidKey(std::string key);
        bool isEmpty(std::string value);
        bool isString(std::string value);
    private:
        std::map<std::string, std::string> data;
}; 
#pragma once 
#include <string> 
#include <map> 

class Object{
    public: 
        void insert(std::string key, std::string value); 
        std::string getValue(std::string name);
    protected: 
        template<typename Value>
        bool isKeyExists(std::map<std::string, Value> data, std::string key);
        bool isValidKey(std::string key);
        bool isEmpty(std::string value);
        bool isString(std::string value);
    private:
        std::map<std::string, std::string> data;
}; 
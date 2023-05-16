#include "Integer.h"


void Integer::insert(std::string key, std::string value= std::string()) {
    try {
        int newValue; 
        if (isEmpty(value)) {
            newValue = std::stoi(value);
        }
            
        if (isValidKey(key)) 
            data[key] = newValue;

    } catch (const std::exception&) {
        std::cout << "Error of type convertion " << "\n";
        return;
    }
}  

int Integer::getValue(std::string name){
    return data[name]; 
}     

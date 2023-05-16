#include "Float.h"

void Float::insert(std::string key, std::string value= std::string()) {
    try {
        double newValue; 
        if (isEmpty(value)) {
            newValue = std::stod(value);
        }
        if (isValidKey(key)) 
            data[key] = newValue;
    } catch (const std::exception&) {
        std::cout << "Error of type convertion " << "\n";
        return;
    }
} 

double Float::getValue(std::string name){
    return data[name]; 
}     
#include <string> 
#include <map> 
#include <iostream> 


class Float: public Integer {
    private:
        std::map<std::string, double> data; 
    public:
        void insert(std::string key, std::string value= std::string()) {
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

        double getValue(std::string name){
            return data[name]; 
        }          
}; 



int main() {
    Object object; 

    object.insert("str", "123"); 

    std::string value = object.getValue("str"); 
    std::cout << value << "\n";
    
    Integer number; 

    number.insert("a", "5621"); 

    int Avalue = number.getValue("a"); 
    std::cout << Avalue << "\n";

    Float b; 

    b.insert("b", "1.321"); 
    
    double Bvalue = b.getValue("b"); 
    std::cout << Bvalue << "\n";

    object.insert("new_str", "hello, world!"); 
    std::string new_value = object.getValue("new_str"); 
    std::cout << new_value << "\n";

    
    return 0;
}

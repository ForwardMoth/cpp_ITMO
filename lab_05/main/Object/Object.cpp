#include <string> 
#include <map> 
#include <tuple>
#include <iostream> 

class Object{
    public: 
        void insert(std::string key, std::string value= std::string()) {
            std::string newValue; 
            if (isEmpty(value))
                newValue = value;
            if (isValidKey(key)) 
                data[key] = newValue;
        }
        std::string getValue(std::string name){
            return data[name]; 
        }

    protected: 
        template<typename Value>
        bool isKeyExists(std::map<std::string, Value> data, std::string key) { 
            auto it = data.find(key); 
            return (it != data.end()) ? true : false; 
        }

        bool isValidKey(std::string key) {
            if (key.length() > 64)
                return false; 
            if (isString(key))
                return false;
            return true;
        }

        bool isEmpty(std::string value) {
            return (value.length() == 0) ? false : true; 
        }

        bool isString(std::string value) {
            for(int i=0; i<value.length(); i++) { 
                if(isdigit(value[i]) == true)
                    return true;
            }
            return false; 
        }

    private:
        std::map<std::string, std::string> data;
}; 


class Integer: public Object {
    private:
        std::map<std::string, int> data; 
    public:
        void insert(std::string key, std::string value= std::string()) {
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

        int getValue(std::string name){
            return data[name]; 
        }       
}; 

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

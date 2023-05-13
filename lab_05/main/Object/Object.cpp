#include <string> 
#include <map> 
#include <tuple>

class Integer{
    private:
        std::map<std::string, int> data;

        bool isEmpty(std::string value) {
            return (value.length() == 0) ? false : true; 
        }

        bool isString(std::string value) {
            for(int i=0; i<value.length(); i++) { 
                if(isdigit(value[i]) == true)
                    return false;
            }
            return true; 
        }

        bool isValidKey(std::string key) {
            if (key.length() > 64)
                return false; 
            if (isString(key))
                return false;
        }

        bool isKeyExists(std::string key) { 
            auto it = data.find(key) 
            return (it != data.end()) ? true : false; 
        }

    public: 
        bool insert(std::string key, string value="") {
            int newValue; 
            if (isEmpty(value))
                newValue = std::stoi(value);
            if (isValidKey(key)) {
                data[key] = newValue;
                return true;
            }
            return false;
        }

        std::tuple<std::string, bool> getValue(std::string name){
            return (isKeyExists(name)) ? std::make_tuple(data[name], true) : std::make_tuple("", false);
        }
}; 
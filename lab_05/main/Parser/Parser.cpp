#include "Parser.h"


void Parser::parse(std::string command, int id) {
    auto start = std::chrono::steady_clock::now();
    Parser::executeCommands(command); 
    auto end = std::chrono::steady_clock::now();
    std::cout << "Thread " << id << " execution time: " << 
    std::fixed << std::setprecision(3) << std::chrono::duration<double>(end - start).count() * 1000 << "\n";
}


void Parser::executeCommands(std::string line) {
    std::vector<std::string> commands = Parser::split(line, ',');

    Object obj;
    Integer int_obj;

    for(std::string command : commands) {
        Parser::distributeCommand(command, obj, int_obj);
    }
        
}


void Parser::distributeCommand(std::string command, Object &obj, Integer &int_obj) {
    if (Parser::findFirstSubstring(command, "loop")) {
        std::vector <int> loop_params = Parser::getLoopParams(command);     

        Parser::getLoopBody(command); 

        std::vector<std::string> loop_commands = Parser::split(command, ';');

        for(std::string com : loop_commands)
            Parser::dropSpaces(com);

        for(int i=loop_params[0]; i < loop_params[1]; i+= loop_params[2])
            for(std::string com : loop_commands) {
                Parser::caseCommands(com, obj, int_obj);
            }
    }
    else {
        Parser::dropSpaces(command); 
        Parser::caseCommands(command, obj, int_obj);
    }
}


std::vector<int> Parser::getLoopParams(std::string command) {
    std::vector<int> a; 
    std::string line = Parser::getLineInBound(command, "(", ")");
    std::vector<std::string> command_elements = Parser::split(line, ':');
    
    for(std::string element : command_elements)
        a.push_back(std::stoi(element));

    return a; 
}


void Parser::caseCommands(std::string command, Object &obj, Integer &int_obj) {

    if(Parser::findFirstSubstring(command, "print")){

        Parser::print(command, obj, int_obj);
    }
    else if (Parser::findFirstSubstring(command, "file"))
    {
        Parser::writeFile(command);
    }
    else if (Parser::findFirstSubstring(command, "int"))
    {
        Parser::initType(command, int_obj);
    }
    else if (Parser::findFirstSubstring(command, "str"))
    {
        Parser::initType(command, obj); 
    } 
    else if (Parser::findFirstSubstring(command,"=")){
        Parser::calculations(command, int_obj);   
    }
}


void Parser::writeFile(std::string command){
    std::string line = Parser::getLineInBound(command, "(", ")");
    std::vector<std::string> command_elements = Parser::split(line, ':');

    Parser::dropBounds(command_elements[0]);

    std::ofstream file(command_elements[0], std::ios::app);

    if(file.is_open()) {
        Parser::dropBounds(command_elements[1]);

        file << command_elements[1];

        file.close();

        std::cout << "Data is written successful." << "\n";
    }
    else 
        std::cout << "Error of openning file!" << "\n";
}


void Parser::dropBounds(std::string &str) {
    str.erase(0, 1);
    str.pop_back();
}


std::string Parser::getLineInBound(std::string value, std::string first, std::string last) {
    std::string line = Parser::findBetweenSymbols(value, first, last);
    Parser::dropBounds(line);
    return line;  
}


void Parser::print(std::string command, Object obj, Integer int_obj) {
    std::string print_line = Parser::getLineInBound(command, "(", ")");

    if (Parser::findFirstSubstring(print_line, "'")){
        Parser::dropBounds(print_line);
        std::cout << print_line << "\n";
    }
    else {
        if (obj.findKey(print_line)){
            std::cout << print_line << "\n";
        } 
        else if (int_obj.findKey(print_line))
        {  
            std::cout << int_obj.getValue(print_line) << "\n";
        }
        else 
            std::cout << "Error! Variable isn't found" << "\n";   
    }
}


void Parser::calculations(std::string command, Integer &int_obj) {
    Parser::dropSpaces(command);
    std::vector<std::string> command_elements = Parser::split(command, ' ');

    if(command_elements.size() == 5) {
        int valueA = Parser::getNumber(command_elements[2], int_obj);
        int valueB = Parser::getNumber(command_elements[4], int_obj);

        if (Parser::findFirstSubstring(command, "+"))
        {
            int_obj.setValue(command_elements[0], valueA + valueB); 
        }
        else if (Parser::findFirstSubstring(command, "-"))
        {
            int_obj.setValue(command_elements[0], valueA - valueB); 
        }
        else if (Parser::findFirstSubstring(command, "*"))
        {
            int_obj.setValue(command_elements[0], valueA * valueB); 
        }
        else if (Parser::findFirstSubstring(command, "/"))
        {
            if (valueB != 0)    
                int_obj.setValue(command_elements[0], valueA / valueB);  
            else
                std::cout << "Error! Division by zero!" << "\n";
        }
    }
}


int Parser::getNumber(std::string str, Integer obj) {
    int value;
    if(Parser::isNumeric(str))   
        value = std::stoi(str);
    else
        value = obj.getValue(str);
    return value;
}


bool Parser::isNumeric(std::string value) {
    for(int i=0;i<value.length();i++) {
        if(!isdigit(value[i])) {
            return false;  
        }
    } 
    return true;  
}


template<typename Type>
void Parser::initType(std::string command, Type &obj){
    std::vector<std::string> command_elements = Parser::split(command, ' ');

    if (command_elements.size() == 2) {
        obj.insert(command_elements[1], "");
    }

    if (command_elements.size() == 4) {
        obj.insert(command_elements[1], command_elements[3]);
    }
}


std::vector<std::string> Parser::split(std::string line, char separator) {
    std::vector<std::string> result; 
    std::stringstream s(line);
    std::string str;
    while(std::getline(s, str, separator)) {
        result.push_back(str);
    }
    return result;
}


bool Parser::findFirstSubstring(std::string str, std::string substr){
    std::size_t found = str.find(substr); 
    return (found != std::string::npos) ? true : false; 
}


void Parser::dropSpaces(std::string &line) {
    std::size_t first = line.find_first_not_of(" "); 
    std::size_t last = line.find_last_not_of(" ");  
    line = line.substr(first, last - first + 1); 
}

std::string Parser::findBetweenSymbols(std::string line,std::string first_symbol, std::string last_symbol)  {
    std::size_t first = line.find(first_symbol);
    std::size_t last = line.find(last_symbol);
    return line.substr(first, last - first + 1);
}


void Parser::getLoopBody(std::string &loop){
    loop = Parser::getLineInBound(loop, "{", "}"); 
    Parser::dropSpaces(loop);
}

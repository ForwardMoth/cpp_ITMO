#include "Parser.h"

void Parser::parse(std::string command, int id) {
    auto start = std::chrono::steady_clock::now();
    Parser::executeCommands(command); 
    auto end = std::chrono::steady_clock::now();
    // std::cout << "Thread " << id << " execution time: " << 
    // std::fixed << std::setprecision(3) << std::chrono::duration<double>(end - start).count() * 1000 << "\n";
}

void Parser::executeCommands(std::string line) {
    std::vector<std::string> commands = Parser::split(line, ';');
    
    for(std::string command : commands) {
        std::cout << command << "\n";
        Parser::distributeCommand(command);
    }
        
}

void Parser::distributeCommand(std::string command) {
    Object obj;
    Integer int_obj;
    Float float_obj;

    if (Parser::findFirstSubstring(command, "loop")) {
        Parser::getLoopBody(command); 
        std::vector<std::string> loop_commands = Parser::split(command, ',');
        for(std::string com : loop_commands) 
            Parser::caseCommands(com, obj, int_obj,float_obj);
    }
    else {
        Parser::caseCommands(command, obj, int_obj,float_obj);
    }
}

void Parser::caseCommands(std::string command, Object &obj, Integer &int_obj, Float &float_obj) {
    if(Parser::findFirstSubstring(command, "print"))    {
        // std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "file"))
    {
        // std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "int"))
    {
        Parser::initType(command, int_obj);
    }
    else if (Parser::findFirstSubstring(command, "str"))
    {
    //    std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "+"))
    {
        // std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "-"))
    {
        // std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "*"))
    {
        // std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "/"))
    {
        // std::cout << command << "\n"; 
    }
}

template<typename Type>
void Parser::initType(std::string command, Type &obj){
    // std::cout << command << "\n";  
    // std::cout << "\n";
    std::vector<std::string> command_elements = Parser::split(command, ' ');

    // for(std::string el : command_elements)
    //     std::cout << el << "\n";

    // if (command_elements.size() == 2) {
    //     obj.insert(command_elements[1], "");
    // }

    // if (command_elements.size() == 4) {
    //     std::cout << command_elements[1] << command_elements[3] << "\n";
    //     // obj.insert(command_elements[1], command_elements[2]);
    // }
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

void Parser::getLoopBody(std::string &loop){
    std::size_t first = loop.find("{");
    std::size_t last = loop.find("}");
    loop = loop.substr(first, last - first + 1); 

    loop.erase(0, 1);
    loop.pop_back();

    first = loop.find_first_not_of(" "); 
    last = loop.find_last_not_of(" ");  
    loop = loop.substr(first, last - first + 1); 
}

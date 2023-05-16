#include "Parser.h"

void Parser::parse(std::string command, int id) {
    auto start = std::chrono::steady_clock::now();
    Parser::executeCommands(command); 
    auto end = std::chrono::steady_clock::now();
    std::cout << "Thread " << id << " execution time: " << 
    std::fixed << std::setprecision(3) << std::chrono::duration<double>(end - start).count() * 1000 << "\n";
}

void Parser::executeCommands(std::string line) {
    std::vector<std::string> commands = Parser::splitLine(line, ';');
    
    for(std::string command : commands) {
        Parser::distributeCommand(command);
    }
        
}

void Parser::distributeCommand(std::string command) {
    if (Parser::findFirstSubstring(command, "loop")) {
        Parser::getLoopBody(command); 
        std::vector<std::string> loop_commands = Parser::splitLine(command, ',');
        
        Object obj;
        Integer int_obj;
        Float float_obj;

        for(std::string com : loop_commands) 
            std::cout << com << "\n";
    }
    else {
        Parser::caseCommands(command);
    }
}

void Parser::caseCommands(std::string command) {
    if(Parser::findFirstSubstring(command, "print"))    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "file"))
    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "int"))
    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "str"))
    {
       std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "+"))
    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "-"))
    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "*"))
    {
        std::cout << command << "\n"; 
    }
    else if (Parser::findFirstSubstring(command, "/"))
    {
        std::cout << command << "\n"; 
    }
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

std::vector<std::string> Parser::splitLine(std::string line, char separator) {
    std::vector<std::string> result; 
    int start = 0;
    int end = 0;
    for(int i=0;i<line.size();i++) {
        if (line[i] == separator) {  
            std::string sub = line.substr(start, end - start); 
            start = end + 1; 
            result.push_back(sub);   
        }
        end += 1; 
    }
    return result;
}
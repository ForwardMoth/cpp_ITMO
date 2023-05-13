#include "Parser.h"

void Parser::parse(std::string command, int id) {
    auto start = std::chrono::steady_clock::now();
    Parser::executeCommands(command); 
    auto end = std::chrono::steady_clock::now();
    std::cout << "Thread " << id << " execution time: " << 
    std::fixed << std::setprecision(3) << std::chrono::duration<double>(end - start).count() * 1000 << "\n";
}

void Parser::executeCommands(std::string line) {
    std::vector<std::string> commands = Parser::splitLine(line);
    
    for(std::string command : commands)
        std::cout << command << "\n"; 
}

std::vector<std::string> Parser::splitLine(std::string line) {
    std::vector<std::string> result; 
    int start = 0;
    int end = 0;
    for(int i=0;i<line.size();i++) {
        if (line[i] == ';') {
            std::string sub = line.substr(start, end - start); 
            start = end + 1; 
            result.push_back(sub);
        }
        end += 1; 
    }
    return result;
}
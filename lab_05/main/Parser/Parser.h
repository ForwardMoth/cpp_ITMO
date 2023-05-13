#pragma once
#include <iostream>
#include <string> 
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>

class Parser {
    public:
        static void parse(std::string command, int id);
    private:
        static void executeCommands(std::string line); 
        static std::vector<std::string> splitLine(std::string line); 
}; 

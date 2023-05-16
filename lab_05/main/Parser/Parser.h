#pragma once
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>
#include "../Float/Float.h"

class Parser {
    public:
        static void parse(std::string command, int id);
    private:
        static void executeCommands(std::string line); 
        static std::vector<std::string> splitLine(std::string line, char separator); 
        static void distributeCommand(std::string command);
        static void getLoopBody(std::string &loop);
        static bool findFirstSubstring(std::string str, std::string substr);
        static void caseCommands(std::string command);
}; 

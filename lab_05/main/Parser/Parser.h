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
        static void distributeCommand(std::string command);
        static void getLoopBody(std::string &loop);
        static bool findFirstSubstring(std::string str, std::string substr);
        static void caseCommands(std::string command, Object &obj, Integer &int_obj, Float &float_obj);
        template<typename Type>
        static void initType(std::string command, Type &obj);
        static std::vector<std::string> split(std::string line, char separator);
}; 

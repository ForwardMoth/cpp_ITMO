#pragma once
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>
#include "../Integer/Integer.h"

class Parser {
    public:
        static void parse(std::string command, int id);
    private:
        static void executeCommands(std::string line); 
        static void distributeCommand(std::string command);
        static void getLoopBody(std::string &loop);
        static bool findFirstSubstring(std::string str, std::string substr);
        static void caseCommands(std::string command, Object &obj, Integer &int_obj);
        static std::vector<std::string> split(std::string line, char separator);
        static bool isNumeric(std::string value);
        static void DropSpaces(std::string &line);
        template<typename Type>
        static void initType(std::string command, Type &obj);
        static int getNumber(std::string str, Integer obj);
        static void calculations(std::string command, Integer &obj); 
        static std::string findBetweenSymbols(std::string line,std::string first_symbol, std::string last_symbol);
        static std::string getLineInBound(std::string value, std::string first, std::string last);
        static void print(std::string command, Object obj, Integer int_obj);
        static void dropBounds(std::string &str);
}; 

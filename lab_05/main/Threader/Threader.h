#pragma once
#include "../Parser/Parser.h"

class Threader {
    private: 
        const int N = 5;
        std::vector <std::string> thread_commands;
        Parser parser;
    public:
        Threader(std::vector <std::string> commands); 
        void executeThread();
};


#pragma once
#include <vector>
#include "../Parser/Parser.h"

class Threader {
    public:
        const int N = 5;
        std::vector <std::string> thread_commands;
        Parser parser;
        Threader(std::vector <std::string> commands); 

        void executeThread();
};


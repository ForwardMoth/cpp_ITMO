#pragma once
#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 

class FileHandler {
public: 
    char *file_name;
    std::vector <std::string> commands;
    FileHandler(char *name); 

    void handle();

    void printCommands();

    private:
        std::ifstream file;
        
        void open();

        void close();

        bool isOpen();

        void read();
};
#pragma once
#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 

class FileHandler {
public: 
    FileHandler(char *name); 
    void handle();
    std::vector<std::string> getCommands(); 

    private:
        std::ifstream file;
        char *file_name;
        std::vector <std::string> commands;
        
        void open();
        void close();
        bool isOpen();
        void read();
};
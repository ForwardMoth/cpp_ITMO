#include "FileHandler.h"

FileHandler::FileHandler(char *name) {
    file_name = name;
}

void FileHandler::handle() {
    open();
    if (isOpen()) {
        read();
    }
    close();
}

void FileHandler::open(){
    file.open(file_name);
}

void FileHandler::close() {
    file.close();
}

bool FileHandler::isOpen() {
    if(!file.is_open()) {
        std::cout << "Error! Couldn't open file." << "\n";
        return false; 
    }
    return true;
}

std::vector<std::string> FileHandler::getCommands() {
    return commands;
}

void FileHandler::read() {
    std::string line;
    while(!file.eof()) {
        line="";
        std::getline(file,line);
        commands.push_back(line); 
    }
}
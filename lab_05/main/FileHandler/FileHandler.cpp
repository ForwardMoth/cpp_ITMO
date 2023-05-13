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

void FileHandler::printCommands() {
    for (int i=0;i<commands.size();i++) 
        std::cout << commands[i] << "\n";
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

void FileHandler::read() {
    std::string line;
    while(!file.eof()) {
        line="";
        std::getline(file,line);
        commands.push_back(line); 
    }
}
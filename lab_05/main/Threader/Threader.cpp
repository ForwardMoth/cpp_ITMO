#include "Threader.h"

Threader::Threader(std::vector<std::string> commands) {
    thread_commands = commands;  
}

void Threader::executeThread() {
    for(int i=0;i < thread_commands.size();i+= N) {
        std::vector <std::thread> threads;
        for(int j=0; j < N; j++) {
            
            threads.push_back(std::thread(Parser::parse, thread_commands[j]));
        }

        for(int j=0; j < N; j++) {
            threads[j].join();
        }
    }
}

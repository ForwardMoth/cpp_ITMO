#include "Threader.h"

Threader::Threader(std::vector<std::string> commands) {
    thread_commands = commands;  
}

void Threader::executeThread() {
    int size = thread_commands.size(); 
    for(int i=0;i<size; i+=N) {
        int start = i; 
        int end = std::min(i+N, size); 

        std::vector <std::thread> threads; 

        for(int j=start; j<end; j++) {
            // Parser::parse(thread_commands[j], j);    

            threads.push_back(std::thread(Parser::parse, thread_commands[j], j)); 
        }

        for(std::thread& thread : threads) {
            thread.join();
        }
    }
}

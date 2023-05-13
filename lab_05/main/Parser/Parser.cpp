#include "Parser.h"

void Parser::parse(std::string command) {
    auto start = std::chrono::steady_clock::now();
    // cout << command << "\n";
    auto end = std::chrono::steady_clock::now();
    std::cout << "Thread " << std::this_thread::get_id() << " execution time: " << 
        std::fixed << std::setprecision(3) << std::chrono::duration<double>(end - start).count() * 1000000 << "\n";
}


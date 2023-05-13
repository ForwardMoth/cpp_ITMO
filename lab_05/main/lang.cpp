#include "FileHandler/FileHandler.h"
#include "Threader/Threader.h"

using namespace std;

void ReadFile(char *name) {
    cout << "Name of file: " << name << '\n';
}

// std::vector<std::string> splitLine(std::string line) {
//     std::vector<std::string> result; 
//     int start = 0;
//     int end = 0;
//     for(int i=0;i<line.size();i++) {
//         if (line[i] == ';') {
//             std::string sub = line.substr(start, end - start); 
//             start = end + 1; 
//             result.push_back(sub);
//         }
//         end += 1; 
//     }
//     return result;
// }

// void print(vector <string> a){
//     for(string el : a)
//         cout << el << "\n";
// }


int main(int argc, char *argv[]) {
    if (argc == 2){
        FileHandler file_handler(argv[1]);
        file_handler.handle();
        // vector <string> commands = file_handler.getCommands();
        // print(commands); 
        // cout << "--------------------------->" << "\n";
        // for (string command : commands) {
        //     vector <string> result = splitLine(command);
        //     print(result);
        // }
        
        Threader threader(file_handler.getCommands());
        threader.executeThread();
    }
    else {
        cout << "Error! Wrong number of arguments" << "\n";
    }

    return 0;       
}
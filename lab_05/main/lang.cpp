#include "FileHandler/FileHandler.h"
#include "Threader/Threader.h"

using namespace std;

void ReadFile(char *name) {
    cout << "Name of file: " << name << '\n';
}


int main(int argc, char *argv[]) {
    if (argc == 2){
        FileHandler file_handler(argv[1]);
        file_handler.handle();
        // file_handler.printCommands();
        Threader threader(file_handler.commands);
        threader.executeThread();
    }
    else {
        cout << "Error! Wrong number of arguments" << "\n";
    }

    return 0;       
}
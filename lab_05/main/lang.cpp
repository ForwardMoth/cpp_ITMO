#include "FileHandler/FileHandler.h"
#include "Threader/Threader.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2){
        FileHandler file_handler(argv[1]);
        file_handler.handle();
        Threader threader(file_handler.getCommands());
        threader.executeThread();
    }
    else {
        cout << "Error! Wrong number of arguments" << "\n";
    }

    return 0;       
}
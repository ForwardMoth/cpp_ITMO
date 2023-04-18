
#include <iostream>
#include <cstring>

using namespace std;

bool CheckNumbers(char *number) {
    for(char* p=&number[0]; *p != '\0'; p++) {
        if (isdigit(*p) == false)
            return false;
    }
    return true; 
}

bool CheckArguments(int argc, char *argv[]){
    if (argc != 4) {
        cout << "Entered wrong count of arguments. Please enter 3 arguments!!!" << "\n";
        return false;
    }

    if (CheckNumbers(argv[1]) == false || CheckNumbers(argv[3]) == false) {
        cout << "Entered wrong type of arguments in 1 or 3 positions." << "\n";
        cout << "Please enter numbers in 1 and 3 positions!!!" << "\n";
    }

    return true; 
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double pow(double a, double b) {
    int result = 1; 
    for(int i=1; i<=b; i++) 
        result *= a;
    return result; 
} 

int main(int argc, char *argv[]){
    if (CheckArguments(argc, argv)) {
        double a = stod(argv[1]);
        double b = stod(argv[3]);
        char* s = argv[2];
        switch (*s) {
            case '+': 
                cout << a << " + " << b << " = " << add(a,b) << "\n";
                break;
            case '-':
                cout << a << " - " << b << " = " << subtract(a,b) << "\n";
                break;
            case '^':
                cout << a << " ^ " << b << " = " << pow(a,b) << "\n";
                break;
            default: 
                cout << "Wrong operator! " << "\n";
                break;
        }
    }

    return 0;
}
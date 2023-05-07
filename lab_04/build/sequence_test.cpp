#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

int FirstFunction(int x) {
    return x * x - x * x + x * 4 - x * 5 + x + x;
}

int SecondFunction(int x) {
    return x + x;
}

int ThirdFunction(int a, int b) {
    return a + b - a;
}

void Calculations(const int N) { 
    auto start = chrono::high_resolution_clock::now();    
    for(int i=0;i<N;i++) {
        int first_result = FirstFunction(i);
        this_thread::sleep_for(chrono::milliseconds(1));
        int second_result = SecondFunction(i);
        this_thread::sleep_for(chrono::milliseconds(1));
        int third_result = ThirdFunction(first_result, second_result);
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start).count(); 
    cout << "Duration " << fixed << setprecision(4) << duration << " seconds" << "\n";
}


int main() {
    const int N = 100;
    const int M = 1000;

    Calculations(N); 
    Calculations(M);

    return 0;
}
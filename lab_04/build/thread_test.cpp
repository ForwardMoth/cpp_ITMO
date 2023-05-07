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
    int first_result, second_result, third_result;   
    for(int i=0;i<N;i++) {
        thread th([&first_result, &i]() { 
            first_result = FirstFunction(i); 
            this_thread::sleep_for(chrono::nanoseconds(1));
        });

        thread th1([&second_result, &i]() {
            second_result = SecondFunction(i);
            this_thread::sleep_for(chrono::milliseconds(1));
        });

        thread th2([&third_result,&first_result,&second_result]() {
            third_result = ThirdFunction(first_result, second_result);
            this_thread::sleep_for(chrono::milliseconds(1));
        });

        th.join();
        th1.join();
        th2.join();
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
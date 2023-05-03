#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    const int N = 100000;

    auto start = chrono::high_resolution_clock::now();  
    int first_result[N], second_result[N], third_result[N];

    for(int i=0;i<N;i++) 
        first_result[i] = i * i - i * i  + 4 * i  - 5 * i + i + i;

    for(int i=0;i<N;i++) 
        second_result[i] = i + i;

    for(int i=0;i<N;i++) 
        third_result[i] = first_result[i] + second_result[i] - first_result[i];
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start).count(); 
    cout << "Duration " << fixed << setprecision(4) << duration << " seconds" << "\n";

    return 0;
}
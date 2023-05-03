#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    const int N = 100000;

    auto start = chrono::high_resolution_clock::now();   
    int fd[2], fd1[2]; 
    int first_result[N], second_result[N], third_result[N]; 

    if (pipe(fd) == -1 || pipe(fd1) == -1) {
        cout << "Failed pipes creations" << "\n";
        return 1;
    }

    pid_t pid1 = fork();

    if (pid1 == -1) {
        cout << "Fork error" << "\n";
        return 1;
    }
    else 
        if (pid1 == 0) {
            for (int i=0;i<N;i++) {
                close(fd[0]);
                close(fd1[0]);
                close(fd1[1]);
                first_result[i] = i * i - i * i  + 4 * i  - 5 * i + i + i;
                write(fd[1], &first_result, sizeof(first_result));
                close(fd[1]);
            }
                
            return 0;
        } 

    pid_t pid2 = fork();

    if (pid2 == -1){
        cout << "Fork error" << "\n";
        return 1;
    } 
    else 
        if (pid2 == 0) {
            for (int i=0;i<N;i++)  {
                close(fd[0]);
                close(fd1[0]);
                close(fd[1]);
                second_result[i] = i + i;
                write(fd1[1], &second_result, sizeof(second_result));
                close(fd1[1]);
            }

            return 0;
        }
    
    
    close(fd[1]);
    close(fd1[1]);

    read(fd[0], &first_result, sizeof(first_result));
    read(fd1[0], &second_result, sizeof(second_result)); 
    

    for(int i=0;i<N;i++) 
        third_result[i] = first_result[i] + second_result[i] - first_result[i];
    
    close(fd[0]);
    close(fd1[0]);       
    
 
    int status;
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start).count(); 
    cout << "Duration " << fixed << setprecision(3) << duration << " seconds" << "\n";

    return 0;
}
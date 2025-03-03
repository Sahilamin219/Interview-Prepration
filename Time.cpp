#include <bits/stdc++.h>
using namespace std;
class Time {
public:
    time_t timeValue;
    Time() {
        timeValue = time(NULL); 
    }
    void printTime() {
        cout<<"Current time in seconds: " <<timeValue<< endl;
    }
};
int main() {
    Time t = Time();  
    t.printTime();
    return 0;
}
// Start timing
time_t start_time = time(NULL);

// Do some work...

// End timing
time_t end_time = time(NULL);

// Calculate difference in seconds
double seconds_elapsed = difftime(end_time, start_time);

cout << "Operation took " << seconds_elapsed << " seconds." << endl;
#include <chrono>

// Start timing
auto start = std::chrono::high_resolution_clock::now();

// Do some work...

// End timing
auto end = std::chrono::high_resolution_clock::now();

// Calculate duration
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

std::cout << "Operation took " << duration.count() << " milliseconds." << std::endl;

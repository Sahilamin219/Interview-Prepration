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

#include <iostream>
#include <chrono>
#include <thread>
#include<fstream>
using namespace std;
int main() {
    try{
        throw(invalid_argument("sahil"));
        cout<<"OKK";
    }
    catch(exception& e){
        cerr << "exception: " << e.what() << std::endl;
    }
    exit(0);
    auto now = chrono::system_clock::now();
    cout << "Current time captured! " <<endl;
    auto start = chrono::high_resolution_clock::now();

    this_thread::sleep_for(chrono::milliseconds(500));  // Simulate work

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Execution time: " << duration.count() << " ms\n";


    chrono::seconds fiveSec(5);
    chrono::milliseconds milliSec = chrono::milliseconds(500);

    cout << "5 seconds in milliseconds: " << fiveSec.count() * 1000 << " ms\n";
    cout << "500 milliseconds: " << milliSec.count() << " ms\n";

    auto start_ = chrono::steady_clock::now();

    this_thread::sleep_for(chrono::seconds(3));

    auto now_ = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::seconds>(now_ - start_);

    if (elapsed.count() >= 2) {
        cout << "More than 2 seconds passed!\n";
    }
    return 0;
}

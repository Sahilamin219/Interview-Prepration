// C++ Program to implement 
// thread_local Storage 
#include <iostream> 
#include <thread> 
using namespace std; 

thread_local int counter = 0; 

void increment_counter() 
{ 
	counter++; 
	cout << "Thread " << this_thread::get_id() 
		<< " counter = " << counter << endl; 
} 

int main() 
{ 
	// Create first thread 
	thread t1(increment_counter); 
	// Create second thread 
	thread t2(increment_counter); 
	// Wait for the first thread to finish 
	t1.join(); 
	// Wait for the second thread to finish 
	t2.join(); 
	return 0; 
}

// C++ Program to demonstrate the use of thread-local 
// storage. 
#include <iostream> 
#include <thread> 
#include <mutex>
using namespace std; 
class Singleton { 
public: 
	static Singleton& getInstance() { 
		// Each thread will have its own instance of 
		// Singleton 
		thread_local Singleton instance; 
		return instance; 
	} 

	void printMessage() { 
		cout << "Hello from thread "
			<< this_thread::get_id() << endl; // will print uniqure id for each thread
	} 
private: 
	Singleton() {};//= default; 
}; 
std::mutex m;
void workerThread() { 
    m.lock();
	Singleton::getInstance().printMessage(); 
	this_thread::sleep_for(2s);
	m.unlock();
} 
int main() { 
    // Use current time as seed for random generator
    srand(time(0));
    workerThread();
	// Create first thread 
	thread t1(workerThread); 
	// Create second thread 
	thread t2(workerThread); 

	// Wait for the first thread to finish 
	t1.join(); 
	// Wait for the second thread to finish 
	t2.join(); 
	string s = "sahil";
    hash<string> h;
    int t = h(s);
    int n = h(s);
    int m = h("amin");
    string k = to_string(h("amin"));
    cout<<t<<" "<<n<<" "<<m<<" "<<k;exit(0);
	return 0; 
}
/*
Hello from thread 135515173766400
Hello from thread 135515173750464
Hello from thread 135515165357760
1109280336 1109280336 -1196744239 5946995034638983633

=== Code Execution Successful ===*/

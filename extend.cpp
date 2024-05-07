#include "bits/stdc++.h"
using namespace std;
class Base {
protected:
    // protected member variable
    int x;
 
public:
    // pure virtual function
    virtual void fun() = 0;
 
    // constructor of Base class
    Base() {}
    void setBase(int i)
    {
        x = i;
        cout << "Constructor of base called\n";
    }
};
 
class Derived : public Base {
    // private member variable
    int y;
 
public:
    // calling the constructor of Base class
    Derived(int i, int j)
    {
        y = j;
        setBase(i);
    }
 
    // implementation of pure virtual function
    void fun()
    {
        cout << "x = " << x << ", y = " << y << '\n';
    }
};
 
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Derived d(4, 5);
 
    // calling the fun() function of Derived class
    d.fun();
 
    // creating an object of Derived class using
    // a pointer of the Base class
    Base* ptr = new Derived(6, 7);
 
    // calling the fun() function using the
    // pointer
    ptr->fun();
    return 0;
}

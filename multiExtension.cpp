#include "bits/stdc++.h"
using namespace std;
class Base{
public:
    virtual void show() = 0;
};
class A : public Base{
public:
    void show(){
        cout<<"A"<<" ";
    }
};
class BA : public A {
public:
    void show(){
        cout<<"BA"<<" ";
    }
};
class CA : public A {
public:
    void show(){
        cout<<"CA"<<" ";
    }
};
class Derived : public BA,CA {
public:
    void show(){
        cout<<"Derived"<<" ";
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Base* d = new A();
    d->show();
    return 0;
}

// In C++ encapsulation can be implemented using Class and access modifiers. Look at the below program:

#include <bits/stdc++.h>
using namespace std;
class Student{
    private:
        int a=20;
    public:
        Student();
        void show(); // using abstraction here 

        void get(){
            cout<<a<<" <- this is from get method\n";
        }
};
Student::Student(){
    cout<<"Constructor Calling Completed !\n";
}

void Student::show(){
    get();
}
int main() {
    Student A;
    A.show();
    srand(time(NULL));
    int arr_len=10;
    int random_index=rand()%arr_len;
    cout<<random_index;
	  return 0;
}

// get show methods are acutally getter and setter for hidden data :)

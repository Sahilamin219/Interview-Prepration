#include "bits/stdc++.h"
using namespace std;
/*
Driver driver; // Create a Driver object
User* sahil = &driver; 
Above is same as below 
User* Sahil = new Driver()
*/
class User{
public:
	string userid;
	string name;
	string type;
	User(){
		this->userid = to_string(rand()%100);
	};
	User(string name){
		this->userid = to_string(rand()%100);
		this->name = name;
	}
};
class Driver : public User{
public:
	Driver(){
		this->type = "Driver";
		cout<<"Driver created !\n";
	}
};
class Rider : public User{
public:
	Rider(){
		this->type = "Rider";
		cout<<"Rider created !\n";
	}
};

// class Interface{
// public:
// 	User user;
// 	Ride ride;
// 	Interface(){
// 		cout<<"Enter user details";
// 		cin>>
// 	}
// }
enum class DataType{
	INT,
	STRING
};
using Typeinfo = variant<int, string>;

class Data{
public:
	// virtual void setValue()  = 0;
	virtual Typeinfo getType()  = 0;
	virtual ~Data() = default;
};
class String : public Data{
public:
	string data;
	String(){};
	void setValue(string data)  {
		this->data = data;
	}
};
class Int : public Data{
public:
	int data;
	Int(){};
	void setValue(int data)  {
		this->data = data;
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	User* sahil = new Driver();
	cout<< sahil->userid<<"\n";
	Typeinfo myVariant = "sahil amin";
	
	visit( [](auto&& args){
		cout<<args<<endl;
	}, myVariant );

	return 0;
}

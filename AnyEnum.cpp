#include <bits/stdc++.h>
using namespace std;

enum class vechile : int{
    car  = 1,
    bike = 2,
    bus = 3
};
int main() {
    map<int,any> m;
    string x = "A"; //string("A");
    m.insert({1,x});
    cout<<any_cast<string>(m[1])<<"\n";
    if( m[1].type() == typeid(string) ){
        cout<<m[1].type().name()<<endl;
    }
    vechile vc = vechile::car;
    switch(vc){
        case(vechile::car):
            cout<<"OK "<<static_cast<int>(vc);
            break;
        default:
            cout<<"\n";
    }
    return 0;
}

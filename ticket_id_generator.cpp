#include "bits/stdc++.h"
using namespace std;
/*
* TICKET ID GENERATOR
which microservices are we generating for and are there mulitple microservices ?
train ticket + bus ticket + airplane tickets
how long should the id be and can it have speacial characters?
As per your wish
how frequent the service will be called ?
it can be 10 request per second or you can calcualte the traffic
Ticket id connection with other entity
-> Journey
-> Itemhoho
-> User
-> Report ID
-> Document 
*/
class TicketIDGen{
public:
    int getProductId(string type){
        return IdFromType(type);
    }

};
class Item : TicketIDGen{
public:
    int productid;
    int price;
    string name;
    Item (){
        productid = getProductId("Electronics");
        printf("constructed product with %d productid \n", productid);
    };
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Item item1 = Item();
    cout<<item1.productid;
    return 0;
}

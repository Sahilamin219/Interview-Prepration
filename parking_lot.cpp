parking slot - grage id ->100
VechileType ->
entry ->
exit ->


Parking Area ( Type,  grage Id)
Bill ( time[], parking area )
Grage( )


(creational, structural )Actors -> ( inheitance, abtraction, desgin pattern ......
parkingarea
Garage
exity (set)
entry (set) counter_id
Ticket ( id, parkingarea, time[] , rate, user_payment_done )

Acctivities->
book parking slot ( find , search_ID, alot) -> Manager (Service)
ticket access ( generate bill)
payment done ( give cost amount, <option-discount,paylatter>) -> manager ( serivce)

Class Point{
    int Lat, Long;
}
enum class Type {
    big, small, medium;
};
enum Class PayType{
    UPI, Credit, Debit
}
Class Parkingareas{
    int id;
    int TotalParkAreas;
    Type type
}
class GarageManager{
    int placePossible()
}
Class Exit{
    int id;
    Point location;
}
Class Entry{
    int id;
    Point location;
}
Class Ticket{
    int id;
    Type type;
    int rate;
    Parkingareas parkingarea
}
Class ParkingManager{
    set<Parkingareas> Parkingareass;
    set<Entry> entry;
    set<Exit> exit;
    PaymentMakingProcess paymentMakingProcess;

    int isavailble()
    Parkingareas getParkingAreaID(Entry entrypoint, Type type) // ?
    bool getTicket( Type type){
        //cost 
    }
    void exitProcessing(Ticket ticket){
        // cal cost
        int  cost = calCost(ticket); 
        paymentMakingProcess.pay( PayType paytype, cost)
        paymentMakingProcess.excute()

    }
}
Class PaymentMakingProcess{
    dopaymentusingCredit();
    dopaymentusingUPI();
    dopaymentusingDebit();

    pay(){
        // do payment
    }

}

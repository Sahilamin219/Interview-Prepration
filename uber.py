import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')


class Passenger:
    def __init__(self,name,phone,location):
        self.name = name
        self.phone = phone
        self.location = location
    def __str__(self):
        return "Passenger"


class Rider:
    def __init__(self,name,phone,location,active,pickPassanger,waitingPassenger):
        self.name = name
        self.phone = phone
        self.location = location
        self.active = active
        self.pickPassanger = pickPassanger
        self.waitingPassenger = waitingPassenger
    def __str__(self):
        return "Rider"

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __str__(self):
        return "Point"




def main():
    a = Passenger("sahil", "9990108490", "Bihar")
    print(a)

if __name__ == "__main__":
    main();

Prboelm: 
DESGIN OLA with following functionality
rider add to system
cab add to system
rider->request(x1,y1) cab -> nearest driver -> to accept request or pass
once the driver reaches the location trip starts, trip ends at destination, fair is calculated by a third party function
payment is done in cash.
complete the ride. 

Class Point:
    int : Xcordinate , Ycordinate;
    bool : IsServiceAvailableAtPoint; ?.1
    
Class User:
    string : Username
    int : phone_no
    Point : user_location_cordinates


Class Passenger extends User:
    String[] : Prefered_mode_of_transport = [...vechile types available] ?.2
    
Class Rider extends User:  ?.3
    String : Drive_Vechile
    List : WaitingPassengers = []
    Bool : active
    String : PickedPassenger
    
getFair(Point Source, Point Destination, Vechile Type, DateTime ) ?.3
    return getTotalFair(...args)
    

getdRider( SourcePoint, DestinationPoint, AllowedVechiles, Passenger ):
    #Pick Nearest Rider/CabDriver
    int farness = 500
    while( FoundRider == "None" ):
        FoundRider = getMatchpostRiders(SourcePoint, farness, Passenger )
        farness += 500
        if( farnes == 5000 ):
            farness=-1
            break
    if( Farness == -1 ) : return "No Rider Found"
    return FoundRider
    
getMatchpostRiders( SourcePoint, Farness, Passenger ):
    AreaRange = PointToArea( sourcePoint.X + Farness, sourcePoint.X - Farness, sourcePoint.Y + Farness, sourcePoint.Y - Farness ) 
    Available_Riders = getRidersInAreaRange( AreaRange )
    showRiders(Available_Riders, Passenger )
    FoundRider = "None"
    for riders in Available_Riders:
        if( riders.PickedPassenger == Passenger ):
            FoundRider  = riders
            UpdateShowRider( Available_Riders, Passenger,  FoundRider )
            Break 
    return FoundRider 
    
getRidersInAreaRange( AreaRange ):
    rider_array
    for all Riders under AreaRange: rider_array.append(Riders)
    return rider_array
    
showRiders( Available_Riders, Passenger ):
    for rider in Available_Riders:
        if(rider.active == True ):rider.WaitingPassenges.add(Passenger)
        
showRiders( Available_Riders, Passenger, FoundRider ):
    for rider in Available_Riders:
        if(rider.active == True or rider != FoundRider ):rider.WaitingPassenges.delete(Passenger)
    
        
PostAcceptedRequest( Rider , Passenger): # OnClick From Rider For Selection of an Trip
    Rider.active = False
    Rider.PickedPassenger = Passenger



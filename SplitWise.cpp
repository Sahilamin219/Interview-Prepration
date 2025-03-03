example :
A -> B = 50
B -> A = 40
outcome A -> B = 10
A,B,C,D
-20,30,10,-20
Functions
Group ( 2 or more )
Show/add Due
    - single( 1 to 1 )
    - group ( 1 to N )
Entity :
Users
Group Name

- Aim : Reduced the trans

Objects :-
Users, Group, Amount
Payment, Notification to all due person

Class User{
    string name
}
Class Group{
    List<User> user;
}
Class Node{
    Users username;
    Double DueAmount=0;
}
Class Transaction{
    int ID;
    User From, To;
    Double Due;
    Time Date;
}
Class Relation{
    User From,to;
}
Class HandlePaymentManager{
    Group group;
    set<Transaction> groupGraph;
    map<User , map< User , Double> > graph;
    NotificationManger notificationManger;
    makeSingleDue(User A, User B , double Amount){
        groupGraph[A][B].DueAmount += Amount;
    }
    makeGroupDue(User A, List<User> users, double Amount){
            if( users.size() == 0 ){
                throw.e( size is zero );
            }
           double eachAmountDue = Amount/( user.size() );
           for( obj i : users ){
                //groupGraph[A] += eachAmountDue;
                Transaction trans = new Transaction( i, A, eachAmount );
                groupGraph.put( trans );
                notificationManger.notify(  A,  i,  groupGraph[A].DueAmount );
           }
    }
    makeDueComplete( User A, User B , Double Amount    ){
        //makePaymentUPi();
        groupGraph[A][B] -= Amount;
        notificationManger.notifyUSerPaymentDone( A, B, Amount);
    }
}

Class NotificationManger{

      notifyUSer( users A, user B ,  double Amount){
            sendMessageE( b " ows ", + A,  this Amount );
      }

      notifyUSerPaymentDone(){
            //
      }
}

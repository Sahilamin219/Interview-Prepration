ATM MAchine
flow,requirement,actors,Acctivities,classes,mannager,entity

show nothing
card insert -> check
money fetch -> ( 500,2000,100,200)
okay->pin 
-> notgood -> re enter
-> all good -> procecss payment -> exit(0)
show nothing

actors;
atm
payment

Acctivities
-> state ( ideal, insert card, show details, check ammount, give money, ideal )
    void stayIdeal()
    void takeMoney()
    void showOptions()
    void processDispenseMoney()

Card card{
    string holderName;
    string accountNumber;
    Date expDate;
    vector<int> pin;
}
class InsertCard implements State {
    ATM atm;
    void insertCard(Card card){
        atm.setCard(card);
    }

}
class EnterAmount implements State {
    ATM atm;
    void amountGiven( int amount){
        atm.checkAmountEntered(amount);
    }
}
class EnterPin implements State {
    ATM atm;
    void checkPin( vector<int> pin){
        atm.matchGivenPin(pin);
    }

}
class TakeOutCard implements State {
    ATM atm;
    void ejectCard( ){
        atm.deleteCurrentCard();
    }
}
interface State {
    void insertCard( Card card);
    void enterAmount(int Amount);
    void enterPin( vector<int> pin);
    void takeOutCard( );

}
enum class Denomination{
    int FiveHunderedDenomination;
    int TwoHunderedDenomination;
    int TwoThousandDenomination;
}   
Class ATM {
    State currentState;
    InsertCard insertCard;
    EnterAmount enterAmount;
    EnterPin enterPin;
    TakeOutCard takeOutCard
    Denomination denomination;
    Card userCard;

    ATM( Denomination denomination){
        this.denomination = denomination; // initailised
    }
    void setCard(Card card){
        userCard = card;
    }
    void checkAmountEntered(int amount);
    void matchGivenPin(vector<int> pin);
    void deleteCurrentCard(){
        userCard = NULL;
    }

}

intialize -> 

class ATMMahine{
    ATMMahine(){

    }
};

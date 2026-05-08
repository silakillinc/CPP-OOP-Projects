#include <iostream>
#include <string>

using namespace std;

class BankAccount{
    private:
    string accountNumber;
    string ownerName;
    double balance;
    double annuallInterestRate;

    public: 
    BankAccount();
    BankAccount(string number, string name, double BankBalance,double Rate);

    string getAccountNumber()const;
    string getName()const;
    double getBalance()const;
    double getInterestRate() const;

    void deposit(double amount);
    bool withdraw(double amount);
    void applyMonthlyInterest();
    void printInfo();
};

BankAccount::BankAccount(){
    ownerName="UNKNOWN";
    accountNumber="UNKNOWN";
    balance=0.0;
    annuallInterestRate=0.0;
}

BankAccount::BankAccount(string number, string name,double BankBalance,double Rate){
    accountNumber= number;
    ownerName=name;
    if(BankBalance>=0){
       balance=BankBalance;
    }else{
        balance=0;
        cout<<"Bakiye negatif olamaz. 0 olarak ayarlandi"<<endl;
    }
    if(Rate>=0){
        annuallInterestRate=Rate;
    }else{
        cout<<"Faiz orani 0 olamaz";
    }
}
string BankAccount::getAccountNumber() const {
    return accountNumber;
}
string BankAccount::getName() const {
    return ownerName;
}
double BankAccount::getBalance()const{
    return balance;
}
double BankAccount::getInterestRate()const{
    return annuallInterestRate;
}
void BankAccount::deposit(double amount){

    if(amount>0){
        balance+=amount;
    }else{
        cout<<"Tutar pozitif olmali";
    }
}
bool BankAccount::withdraw(double amount){
    if(amount>0 && balance>=amount){
        balance-=amount;
        return true;
    }else{
        return false;
    }
}
void BankAccount::applyMonthlyInterest(){
    double monthlyInterest= balance* (annuallInterestRate/100.0/12.0);
    balance += monthlyInterest;
}
void BankAccount:: printInfo(){
    cout<<"Hesap NO: "<<accountNumber<<endl;
    cout<<"Name: "<<ownerName<<endl;
    cout<<"Balance: "<<balance<<endl;
    cout<<"Annual Interest Rate: %"<<annuallInterestRate<<endl;
}
int main(){

    BankAccount myObj("123456","Alice",1000,6.0);
    myObj.printInfo();
    cout<<endl;
    myObj.deposit(500.0);
    cout<<"New Balance: "<<myObj.getBalance()<<endl;
    myObj.withdraw(200.0);
    cout<<"New Balance After Draw: "<<myObj.getBalance()<<endl;
    if(!myObj.withdraw(1400.0)){
        cout<<"Balance is still: "<<myObj.getBalance()<<endl;
    }
    cout<<endl;
    cout<<"Applying one month interest: "<<endl;
    myObj.applyMonthlyInterest();
    cout<<"New Balance: "<<myObj.getBalance()<<endl;
    cout<<endl;
    cout<<"Final account info: "<<endl;
    myObj.printInfo();

    return 0;
}
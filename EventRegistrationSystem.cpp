#include <iostream>
#include <string>

using namespace std;

class EventServer{
    private:
    string EventName;
    int maxCapacity;
    int currentUserCount;
    string* userNames;
    int* ticketIDs;

    public:
    EventServer(int capacity);
    ~EventServer();
    void setEventName(string name);
    string getEventName();
    int getCurrentCount();
    bool registerUser(string uName,int tID);
    void printAllUsers();
};
EventServer::EventServer(int capacity){
    EventName="UNKNOWN";
    currentUserCount=0;
    maxCapacity=capacity;
    userNames=new string[capacity];
    ticketIDs= new int[capacity];
}
EventServer::~EventServer(){
    delete[] userNames;
    delete[] ticketIDs;
    cout<<"Hafiza temizlendi"<<endl;
}
void EventServer:: setEventName(string name){
    if(name!=" "){
        EventName=name;
    }else{
        cout<<"Hata"<<endl;
    }
}
string EventServer::getEventName(){
    return EventName;
}
int EventServer:: getCurrentCount(){
    return currentUserCount;
}
bool EventServer:: registerUser(string uName, int tID){
    if(currentUserCount<maxCapacity){
        userNames[currentUserCount]=uName;
        ticketIDs[currentUserCount]=tID;
        currentUserCount++;
        return true;
    }else{
        cout<<"HATA"<<endl;
        return false;
    }
}
void EventServer:: printAllUsers(){
    cout<<"Event Name: "<<EventName<<endl;
    cout<<"Capacity: "<<currentUserCount<<"/"<<maxCapacity<<endl;
    for(int i=0;i<currentUserCount;i++){
        cout<<i+1<<"User: "<<userNames[i]<<" - Ticket ID: "<<ticketIDs[i]<<endl;
    }
}
int main(){

    EventServer* myObj=new EventServer(3);
    myObj->setEventName("C++ Zirvesi");
    myObj->registerUser("Sila",101);
    myObj->registerUser("Erva",102);
    myObj->registerUser("Melisa",103);
    myObj->registerUser("Ayse",104);
    myObj->printAllUsers();
    delete myObj;
    return 0;
}
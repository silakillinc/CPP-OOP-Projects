#include <iostream>
#include <string>
using namespace std;

class Sera{
    private:
    string sensorName;
    int capacity;
    int currentCount;
    double* dataArray;

    public:
    Sera(string name, int maxCapacity);
    ~Sera();
    bool addData(double Value);
    double calculateAverage();
    void printReport();
};
Sera::Sera(string name, int maxCapacity){
    sensorName=name;
    currentCount=0;
    if(maxCapacity>0){
        capacity=maxCapacity;
    }else{
        capacity=5;
    }
    dataArray= new double[capacity];
}
Sera::~Sera(){
    delete []dataArray;
    cout<<sensorName<<" deleted from memory"<<endl;
}
bool Sera::addData(double Value){
    if(currentCount<capacity){
        dataArray[currentCount]=Value;
        currentCount++;
        return true;
       }else{
        cout<<"Capacity is full"<<endl;
        return false;
    }
  }
        
double Sera::calculateAverage(){
    double sum=0.0;
    if(currentCount==0){
        return 0.0;
    }else {
        for(int i=0;i<currentCount;i++){
            sum+=dataArray[i];  
        }
            return sum/currentCount;
    }
}
void Sera::printReport(){
    cout<<"Sensor Name: "<<sensorName<<endl;
    cout<<"Sensor Capacity: "<<capacity<<endl;
    cout<<"Current Data Count: "<<currentCount<<endl;
    cout<<"Data: "<<endl;
    for(int i=0;i<currentCount;i++){
        cout<<dataArray[i]<<endl;
    }
    cout<<"Average: "<<calculateAverage()<<endl;
}

int main(){

    Sera* myObj=new Sera("Sera_1",3);
    myObj->addData(22.5);
    myObj->addData(23.0);
    myObj->addData(24.1);
    myObj->addData(25.0);

    myObj->printReport();
    delete myObj;
    return 0;
}
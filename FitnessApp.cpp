#include <iostream>
#include <string>
using namespace std;

class FitnessApp{
    private:
    string userName;
    int maxDays;
    int currentDayCount;
    int* stepsArray;

    public:
    FitnessApp(int capacity);
    ~FitnessApp();
    void setUserName(string name);
    string getUserName();
    bool addDailySteps(int steps);
    double calculateAverageSteps();
    int findMaxSteps();
    void printReport();
};
FitnessApp::FitnessApp(int capacity){
    maxDays=capacity;
    currentDayCount=0;
    userName="UNKNOWN";
    stepsArray= new int[maxDays];
}
FitnessApp::~FitnessApp(){
    delete[]stepsArray;
    cout<<"Memory cleared";
}
void FitnessApp::setUserName(string name){
    if(name !=" "){
        userName=name;
    }else{
        cout<<"Name cannot be empty"<<endl;
    }
}
string FitnessApp::getUserName(){
    return userName;
}
bool FitnessApp::addDailySteps(int steps){
    if(currentDayCount <maxDays && steps>=0){
        stepsArray[currentDayCount]=steps;
        currentDayCount++;
    }else{
        cout<<"Hata"<<endl;
        return false;
    }
}
double FitnessApp::calculateAverageSteps(){
    double sum=0.0;
    if(currentDayCount==0){
        return 0;
    }else{
      for(int i=0;i<=currentDayCount;i++){
         sum+=stepsArray[i];
        }  
    }
    return sum/currentDayCount;
}
int FitnessApp::findMaxSteps(){
    if(currentDayCount==0){
        return 0;
    }
    int maxIndex=0;
    for(int i=0;i<=currentDayCount;i++){
        if(stepsArray[i]>stepsArray[maxIndex]){
            maxIndex=i;
        }
    }
    return stepsArray[maxIndex];
}
void FitnessApp:: printReport(){
    cout<<"Name: "<<userName<<endl;
    cout<<"Daily Steps: ";
    for(int i=0;i<=currentDayCount;i++){
        cout<<stepsArray[i]<<" ";
    }
    cout<<"The average: "<<calculateAverageSteps()<<endl;
    cout<<"Maximum steps: "<<findMaxSteps()<<endl;
}

int main(){
    FitnessApp myObj(7);
    myObj.setUserName("Sila_Kilinc");

    myObj.addDailySteps(8500);
    myObj.addDailySteps(12000);
    myObj.addDailySteps(5400);
    myObj.addDailySteps(10200);

    myObj.printReport();
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class CourseGrade{
    private:
    string studentName;
    double midterm;
    double finalExam;
    double homeworkAverage;

    public:
    CourseGrade();
    CourseGrade(string name, double mid,double fin,double hw);

    string getName();
    double getMid();
    double getFinal();
    double getHomework();
    void setMidterm(double newMidterm);
    void setFinal(double newFinal);
    void setHomework(double newHW);
    double calculateFinalScore();
    string calculateLetterGrade();
    bool isPassed();
    void printReport();
};
CourseGrade::CourseGrade(){
        studentName="Unknown";
        midterm=0;
        finalExam=0;
        homeworkAverage=0;
}
CourseGrade::CourseGrade(string name, double mid,double fin,double hw){
    studentName=name;
    if(mid>=0 && mid<=100){
        midterm=mid;
    }else{
        midterm=0;
    }
    if(fin>=0 && fin<=100){
        finalExam=fin;
    }else{
        finalExam=0;
    }
    if(hw>=0 && hw<=100){
        homeworkAverage=hw;
    }else{
        homeworkAverage=0;
    }
}

string CourseGrade::getName(){
    return studentName;
}
double CourseGrade::getMid(){
    return midterm;
}
double CourseGrade::getFinal(){
    return finalExam;
}
double CourseGrade::getHomework(){
    return homeworkAverage;
}
void CourseGrade::setMidterm(double newMidterm){

    if(newMidterm>=0 && newMidterm <=100){
        midterm=newMidterm;
    }else{
        cout<<"Invalid score"<<endl;
    }
}

void CourseGrade::setFinal(double newFinal){
    if(newFinal>=0 && newFinal <=100){
        finalExam=newFinal;
    }else{
        cout<<"Invalid score"<<endl;
    }
}

void CourseGrade::setHomework(double newHW){
    if(newHW>=0 && newHW <=100){
        homeworkAverage=newHW;
    }else{
        cout<<"Invalid score"<<endl;
    }
}
double CourseGrade::calculateFinalScore(){
    double final=0;
    final= ((midterm*30)+(finalExam*40)+(homeworkAverage*30))/100.0;
    return final;
}
string CourseGrade::calculateLetterGrade(){
    double final=calculateFinalScore();

    if(final>=90){
        return "A";
    }else if(final>=80){
        return "B";
    }else if(final>=70){
        return "C";
    }else if(final>=60){
        return "D";
    }else{
        return "F";
    }
}
bool CourseGrade::isPassed(){
    string letter= calculateLetterGrade();
    if(letter=="F"){
        return false;
    }else{
        return true;
    }
}
void CourseGrade::printReport(){
    cout<<"------------------"<<endl;
    cout<<"Student: "<<studentName<<endl;
    cout<<"Final Score: "<<calculateFinalScore()<<endl;
    cout<<"Letter Grade: "<<calculateLetterGrade()<<endl;

    if(isPassed()){
        cout<<"Status: PASSED"<<endl;
    }else{
        cout<<"Status: FAILED"<<endl;
    }
}
  

int main(){
    CourseGrade myObj("Alice",40.5,70.0,95.3);
    cout<<"Initial Grade Report: "<<endl;

    myObj.printReport();
    cout<<"Updating midterm score to 90.2"<<endl;
    myObj.setMidterm(90.2);
    cout<<endl;
    cout<<"New Report is: "<<endl;
    myObj.printReport();
    return 0;
}
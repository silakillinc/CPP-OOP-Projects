#include <iostream>
#include <string>
using namespace std;

class LibraryBranch{
    private:
    string branchName;
    int maxCapacity;
    int currentBookCount;
    string* bookTitles;
    bool* isAvailable;

    public:
    LibraryBranch(int capacity);
    ~LibraryBranch();
    void setBranchName(string name);
    string getBranchName();
    bool addBook(string title);
    bool borrowBook(string title);
    void printInventory();
};
LibraryBranch::LibraryBranch(int capacity){
    maxCapacity=capacity;
    currentBookCount=0;
    branchName="Main_Branch";
    bookTitles= new string[capacity];
    isAvailable= new bool [capacity];
}
LibraryBranch::~LibraryBranch(){
    delete[] bookTitles;
    delete[] isAvailable;
    cout<<"Memory freed";
}
void LibraryBranch:: setBranchName(string name){
    if(name==" "){
        cout<<"Branch name cannot be empty"<<endl;
    }else{
        branchName=name;
    }
}
string LibraryBranch:: getBranchName(){
    return branchName;
}
bool LibraryBranch:: addBook(string title){
    if(currentBookCount<maxCapacity){
        bookTitles[currentBookCount]=title;
        isAvailable[currentBookCount]=true;
        currentBookCount++;
        cout<<"Book added: "<<title<<endl;
        return true;
    }else{
        cout<<"Library is full"<<endl;
        return false;
    }
    }

bool LibraryBranch:: borrowBook(string title){
    for(int i=0;i<currentBookCount;i++){
        if(bookTitles[i]==title&& isAvailable[i]==true){
            isAvailable[i]=false;
            cout<<"Success: "<<title<<" is borrowed."<<endl;
        }else{
            cout<<"Failed: "<<title<<" is not available"<<endl;
            return false;
        }
    }
}
void LibraryBranch::printInventory(){
    cout<<"Branch name: "<<branchName<<endl;
    cout<<"Capacity: "<<currentBookCount<<endl;
    
    for(int i=0;i<currentBookCount;i++){
        cout<<i+1<<" ."<<bookTitles[i]<<" - Status: ";
        if(isAvailable[i]==true){
            cout<<"Avaliable"<<endl;
        }else{
            cout<<"Borrowed"<<endl;
        }
    }
}


int main(){

    LibraryBranch myObj(2);
    myObj.setBranchName("City_Library");

    myObj.addBook("C++_Primer");
    myObj.addBook("Clean_code");
    myObj.addBook("Design_Patterns");

    myObj.printInventory();

    myObj.borrowBook("C++_Primer");
    myObj.borrowBook("C++_Primer");

    myObj.printInventory();
    return 0;
}
#include<iostream>
using namespace std;

class Student{
private:
    string name;
    int age, roll_number;
    string grade;
    // Function Getter and Setter
public:
    void setname(string s){
        if(s.size()==0){
            cout << "Invalid Name";
            return;
        }
        name = s;
    }
    void setage(int a){
        if(a<0 || a>100){
            cout << "Invalid Age";
            return;
        }
        age = a;
    }
    void setroll_number(int r){
        roll_number = r;
    }
    void setgrade(string g){
        grade = g;
    }
    void getname(){
        cout << name << endl;
    }
    void getage(){
        cout << age << endl;
    }
    int getroll_number(){
        return roll_number;
    }
    string getgrade(int pin){
        if(pin == 123){
            return grade;
        }
        return " ";
    }
};

int main(){
    Student S1;
    S1.setname("Rohit");
    S1.setage(10);
    S1.setroll_number(21);
    S1.setgrade("A+");
    S1.getname();
    S1.getage();
    cout << S1.getroll_number() << endl;
    cout << S1.getgrade(123) << endl;
}
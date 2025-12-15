#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int age, roll_number;
    string grade;
};

int main(){
    Student S1;
    S1.name = "Rohit";
    S1.age = 10;
    S1.roll_number = 21;
    S1.grade = "A+";

    cout << S1.name << " " << S1.age << " " << S1.roll_number << " " << S1.grade << endl;

    Student S2;
    S2.name = "Mohit";
    S2.age = 12;
    S2.roll_number = 121;
    S2.grade = "B+";

    cout << S2.name << " " << S2.age << " " << S2.roll_number << " " << S2.grade << endl;
}
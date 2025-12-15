/*
Inheritance is the capability of class to derive property and characteristics from another class
__________________________________________________________________________
|             |                   Type of Inheritance                     |
|Base Class   |   Public Mode   |   Protected Mode   |    Private Mode    |
|Public       |       Public    |      Protected     |      Private       |
|Protected    |     Protected   |      Protected     |      Private       |
|Private      |       Private   |      Private       |      Private       |
|_____________|_________________|____________________|____________________|
*/
// #include<iostream>
// using namespace std;

// class Human{
// public:
//     string name;
//     int age, weight;
// };

// class Student : protected Human{
// private:
//     int roll_number, fees;

// public:
//     void fun(string n, int a, int w){
//         name = n;
//         age = a;
//         weight = w;
//     }

//     void display(){
//         cout << name << " " << age << " " << weight << endl;
//     }
// };

// int main(){
//     Student A;
//     A.fun("Rohit", 10, 50);
//     A.display();
// }
#include<iostream>
using namespace std;

class Human{
    string religion, color;
public:
    string name;
    int age, weight;
};

class Student: protected Human{
private:
    int roll_number, fees;

public:
    Student(string name, int age, int weight, int roll_number, int fees){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display(){
        cout << name << " age is " << age << ", weight is " << weight << ", roll number is " << roll_number << ", fees is " << fees << endl;
    }
};

class Teacher: public Human{
    int salary, id;
};

int main(){
    Student A("Rohit", 12, 400, 23, 200);
    A.display();
    Teacher B;
    B.name = "Mohit";
}
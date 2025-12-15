#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number;
    int balance;
    int *roi;

public:
    // Default Constructor
    Customer(){
        name = "Rohit";
        account_number = 5;
        balance = 100;
        roi = new int[100];
    }

    // // Parameterized Constructor
    // Customer(string name, int account_number, int balance){
    //     this->name = name;
    //     this->account_number = account_number;
    //     this->balance = balance;
    // }

    // Constructor Overloading
    Customer (string a, int b){
        name  = a;
        account_number = b;
        balance = 50;
    }

    // Inline Constructor
    inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c){

    }

    // Copy Constructor
    Customer(Customer &B){
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }
    void display(){
        cout << name << " " << account_number << " " << balance << endl;
    }
};

int main(){
    Customer A1;
    Customer A2("Rohit", 23,1000);
    Customer A3("Mohit", 25);
    A1.display();
    A2.display();
    A3.display();
    Customer A4(A3);
    A4.display();
    Customer A5;
    A5 = A3;
    A5.display();
}
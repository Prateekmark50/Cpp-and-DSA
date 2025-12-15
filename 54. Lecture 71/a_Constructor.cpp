#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number;
    int balance;

public:
    // Default Constructor
    Customer(){
        name = "Rohit";
        account_number = 5;
        balance = 100;
    }
    // Parameterized Constructor
    Customer(string a, int b, int c){
        name = a;
        account_number = b;
        balance = c;
    }
    // Constructor Overloading
    Customer (string a, int b){
        name  = a;
        account_number = b;
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
}
/* 
Encapslation is wrapping up of data and information in a single unit, whlie controlling access to them.

where data is variable and information is function
*/
#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number, balance;
    int age;

public:
    Customer(string name, int account_number, int balance, int age){
        this->name = name;
        this->account_number= account_number;
        this->balance = balance;
        this->age = age;
    }

    void updateage(int age){
        if(age>0 && age<100){
            this->age = age;
        }
        else{
            cout <<"Invalid Age\n";
        }
    }

    void deposit(int amount){
        if(amount>0){
            balance += amount;
        }
        else{
            cout << "Invalid amount\n";
        }
    }

    void withdraw(int amount){
        if(amount <= balance && amount > 0){
            balance -= amount;
        }
    }

    void display(){
        cout << name << " " << account_number << " " << balance << " " << age << endl;
    }
};

int main(){
    Customer A1("Rohit", 1, 1000, 3);
    Customer A2("Mohit", 2, 1800, 4);
    Customer A3("Mohan", 3, 2000, 8);
    A1.updateage(24);
    A1.deposit(10);
    A1.display();
}
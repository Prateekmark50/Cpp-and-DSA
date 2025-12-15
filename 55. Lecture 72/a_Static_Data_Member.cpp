// They are attributes of classes or class member
#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number, balance;
    static int total_customer; // Static Data Member
    static int total_balance;

public:
    Customer(string name, int account_number, int balance){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }
    static void acceStatic(){
        cout << "Total number of Customer: " << total_customer << endl;
        cout << "Total Balance:" << total_balance << endl;
    }
    void deposit(int amount){
        if(amount>0){
            balance += amount;
            total_balance += amount;
        }
    }
    void withdraw(int amount){
        if(amount <= balance && amount > 0){
            balance -= amount;
            total_balance -= amount;
        }
    }
    void display(){
        cout << name << " " << account_number << " " << balance << " " << total_customer <<endl;
    }
    void display_totalcustomer(){
        cout << total_customer << endl;
    }
};

int Customer::total_customer=0;
int Customer::total_balance=0;

int main(){
    Customer A1("Rohit", 1, 1000);
    Customer A2("Mohit", 2, 1800);
    A1.display();
    A2.display();
    Customer A3("Mohan", 3, 2000);
    A1.deposit(800);
    Customer::acceStatic();
    A3.display();
    A2.display_totalcustomer();
    A1.display();
}
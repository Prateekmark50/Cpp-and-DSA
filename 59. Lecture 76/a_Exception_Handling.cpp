/*
Exception Handling
A exception is an unexpected problem that arises during the execution of a program and our program terminates suddenly with some errors/issues. Exception occurs during the running of the program.

Try :- It represent a block of code that may throw an exception placed inside the try block. 
It's followed by one or more catch blocks. If an exception occurs, try block throws that exception.

Catch :- It represent a block of code that is executed when a particular exception is thrown from the try block.
The code to handle the exception is written inside the catch block.

Throw :- An exception in C++ can be thrown using the throw keyword.
When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception
*/ 
// #include<iostream>
// using namespace std;

// class Customer{
//     string name;
//     int balance, account_number;

//     public:

//     Customer(string name, int balance, int account_number){
//         this->name = name;
//         this->balance = balance;
//         this->account_number = account_number;
//     }
//     // Deposit
//     void deposit(int amount){
//         if(amount>0){
//             balance += amount;
//             cout << amount << " is credited successfully" << endl;
//         }
//         else{
//             cout << "Amount should be greater than 0" << endl;
//         }
//     }
//     // Withdraw
//     void withdraw(int amount){
//         if(amount>0 && amount <= balance){
//             balance += amount;
//             cout << amount << " is debited successfully" << endl;
//         }
//         else if(amount < 0){
//             cout << "Amount should be greater than 0" << endl;
//         }
//         else{
//             cout << "Your balance is low";
//         }
//     }
// };

// int main(){
//     Customer C1("Rohit", 5000, 10);
//     C1.deposit(100);
//     C1.withdraw(6000);
// }

#include<iostream>
using namespace std;

class Customer{
    string name;
    int balance, account_number;

    public:

    Customer(string name, int balance, int account_number){
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    // Deposit
    void deposit(int amount){
        if(amount>0){
            balance += amount;
            cout << amount << " is credited successfully" << endl;
        }
        else{
            throw "Amount should be greater than 0";
        }
    }
    // Withdraw
    void withdraw(int amount){
        if(amount>0 && amount <= balance){
            balance += amount;
            cout << amount << " is debited successfully" << endl;
        }
        else if(amount < 0){
            throw "Amount should be greater than 0";
        }
        else{
            throw "Your balance is low";
        }
    }
};

int main(){
    Customer C1("Rohit", 5000, 10);
    try{
        C1.deposit(100);
        C1.withdraw(6000);
        C1.deposit(100);
    }
    catch(const char *e){
        cout << "Exception Occured: " << e << endl;
    }
}
/*
#include<iostream>
#include<exception>
using namespace std;

// class exception{
//     protected:
//     string msg;

//     public:
//     exception(string msg){
//         this->msg = msg;
//     }
//     string what(){
//         return msg;
//     }
// };

// class runtime_error : public exception{
//     public:
//     runtime_error(const string &msg): exception(msg){

//     };
// };

class InvalidAmountError: public runtime_error{
    public:

    InvalidAmountError(const string &msg) : runtime_error(msg);
};

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
        if(amount <= 0){
            throw runtime_error("Amount should be greater than 0");  
        }
        balance += amount;
        cout << amount << " Rs is credited successfully" << endl;
    }
    // Withdraw
    void withdraw(int amount){
        if(amount>0 && amount <= balance){
            balance -= amount;
            cout << amount << " is debited successfully" << endl;
        }
        else if(amount < 0){
            throw runtime_error("Amount should be greater than 0");
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
    catch(const runtime_error &e){
        cout << "Exception Occurred: " << e.what() << endl;
    }
    catch(const bad_alloc &e) {
        cout << "Exception Occurred: " << e.what() << endl;
    }
    catch(...){
        cout << "Exception Occurred" << endl;
    }
}
*/

// Now we will make our own Exception 
#include<iostream>
#include<exception>
using namespace std;

class InvalidAmountError: public runtime_error{
    public:
    InvalidAmountError(const string &msg) : runtime_error(msg){

    };
};

class InsufficientBalanceError : public runtime_error{
    public:
    InsufficientBalanceError(const string &msg) : runtime_error(msg){

    };
};

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
        if(amount <= 0){
            throw InvalidAmountError("Amount should be greater than 0");  
        }
        balance += amount;
        cout << amount << " Rs is credited successfully" << endl;
    }
    // Withdraw
    void withdraw(int amount){
        if(amount>0 && amount <= balance){
            balance -= amount;
            cout << amount << " is debited successfully" << endl;
        }
        else if(amount < 0){
            throw InvalidAmountError("Amount should be greater than 0");
        }
        else{
            throw InsufficientBalanceError("Your balance is low");
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
    catch(const InvalidAmountError &e){
        cout << "Exception Occurred: " << e.what() << endl;
    }
    catch(const InsufficientBalanceError &e) {
        cout << "Exception Occurred: " << e.what() << endl;
    }
    catch(...){
        cout << "Exception Occurred" << endl;
    }
}
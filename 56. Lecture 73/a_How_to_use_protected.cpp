#include<iostream>
using namespace std;
/*
                External Code   Within Class    Derived Clas
public:             yes             yes             yes
protected:          no              yes             yes
private:            no              yes             no
*/
class Human{
private:
    int a;
protected:
    int b;
public:
    int c;

    void fun(){
        a = 10;
        b = 20; 
        c = 30;
    }
};

int main(){
    Human Rohit;
    Rohit.c = 10;
    Rohit.fun();
}
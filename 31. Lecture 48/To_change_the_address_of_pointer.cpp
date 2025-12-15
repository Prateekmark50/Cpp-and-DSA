#include<iostream>
using namespace std;

// Value of p does not change
void fun(int *ptr){
    ptr++;
}

// Value of p gets change
void fun1(int **ptr1){
    *ptr1 = *ptr1 + 1;
}

// Value of p gets change using reference variable
void fun2(int *&temp){
    temp++;
}

int main(){
    int n = 10;
    int *p = &n; // single pointer
    int **p2 = &p; // double pointer
    cout << p << endl;

    // Through this value of p does not change
    fun(p);
    cout << "After fun(p) that is original address: " << p << endl;

    // Through this value of p gets change
    fun1(p2);
    cout << "After fun1(p2): " << p << endl;

    // Through this, value of p gets changed using reference variable
    fun2(p);
    cout << "After fun2(p): " << p << endl;
}
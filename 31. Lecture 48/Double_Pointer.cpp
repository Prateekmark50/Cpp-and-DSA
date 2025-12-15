#include<iostream>
using namespace std;

void fun(int *p1){
    *p1 = *p1 + 5;
}

int main() {
    int n = 10;
    int *p = &n; // single pointer
    int **p2 = &p; // Double Pointer
    int ***p3 = &p2; // Triple Pointer
    cout << p << endl;
    cout << &p << endl;
    cout << p2 << endl;
    cout << &p2 << endl;
    cout << p3 << endl;
    // // Value ko modify karna ho, jo n mein rakhi hai..
    // *p = *p +5; // OR We can write like this also **p2 = **p2 + 5; OR ***p3 = ***p3 + 5;
    // cout << n << endl;

    // To modify the value of n using pointer p using function
    fun(p);
    cout << n << endl;
}
#include<iostream>
using namespace std;

int main() {
    // variable ke liye heap memory allocate karo
    int *ptr = new int;
    *ptr = 5; // value assign
    cout << *ptr << endl;

    float *ptr2 = new float;
    *ptr2 = 3.6;
    cout << *ptr2 << endl;

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *p = new int [n];
    // value daloo
    for (int  i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    // print kara do
    for (int i = 0; i < n; i++) {
        cout << p[i] << endl;
    }

    // delete keyword use
    delete ptr;
    delete ptr2;
    delete[] p;
}
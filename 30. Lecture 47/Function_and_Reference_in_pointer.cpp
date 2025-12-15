#include<iostream>
using namespace std;

int swapping1(int p1, int p2) {
    int temp = p1;
    p1 = p2;
    p2 = temp;
    cout << "The address of p1: " << &p1 << endl;
    cout << "The address of p2: " << &p2 << endl;
    cout << "The value at p1 and p2: " << p1 << " " << p2 << endl;
}

int swapping2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "The address of p1: " << &p1 << endl;
    cout << "The address of p2: " << &p2 << endl;
    cout << "The value of p1 and p2: " << p1 << " " << p2 << endl;
    cout << "The value of *p1 and *p2: " << *p1 << " " << *p2 << endl;
}

int swapping3(int &p1, int &p2) {
    int temp = p1;
    p1 = p2;
    p2 = temp;
    cout << "The address of p1: " << &p1 << endl;
    cout << "The address of p2: " << &p2 << endl;
    cout << "The value of p1 and p2: " << p1 << " " << p2 << endl;
}

int main() {
    int first = 10, second = 20;
    cout << "The address of first: " << &first << endl;
    cout << "The address of second: " << &second << endl;

    // // Call-By-Value
    // swapping1(first, second);
    // cout << "The value of first and second: " << first << " " << second << endl;

    // // Call-By-Reference with a Pointer Argument
    // swapping2(&first, &second);
    // cout << "The value of first and second: " << first << " " << second << endl;
    // cout << "The address of first: " << &first << endl;
    // cout << "The address of second: " << &second << endl;

    // Call-By-Reference with a Reference Argument
    swapping3(first, second);
    cout << "The value of first and second: " << first << " " << second << endl;
    int num = 10;
    int &temp = num;
    cout << temp << endl;
    temp++;
    cout << num << endl;
    cout << temp << endl;
    cout << &temp << endl;
    cout << &num << endl;
}
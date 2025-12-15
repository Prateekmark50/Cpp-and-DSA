#include<iostream>
using namespace std;
int main() {
    char arr[] = "12345";
    char *ptr = arr;
    cout << arr << endl;
    cout << ptr << endl;
    cout << (void*)arr << endl;
    cout << (void*)ptr << endl;
    char name = 'a';
    char *ptr1 = &name;
    cout << name <<endl;
    cout << &name <<endl;
    cout << ptr1 << endl;
    cout << (void*)&name << endl;
    cout << (void*)ptr1 << endl;
    // Instead of (void*) we can write static_cast
    cout << static_cast<void*>(arr) << endl;
}
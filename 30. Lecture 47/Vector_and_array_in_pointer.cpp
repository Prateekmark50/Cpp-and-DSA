#include<iostream>
#include<vector>
using namespace std;

// Calling vector with call-by-reference with a reference argument 
void pass(vector<int>&temp) {
    for (int i =0; i < 5; i++) {
        temp[i] = 20;
    }
}

// Calling array with call-by-reference with a pointer argument
void dob(int p[]) {
    for (int i = 0; i < 5; i++) {
        p[i] = p[i] * 2;
    }
}

// Calling vector with call-by-reference with a pointer argument
void pass1(vector<int> *temp1) {
    for (int i =0; i < 5; i++) {
        (*temp1)[i] = 10;
    }
}

// Calling array with call-by-reference with a reference argument
void dob1(int (&p1)[5]) {
    for (int i = 0; i < 5; i++) {
        p1[i] = p1[i] * 3;
    }
}

/*
NOTE:-
1. vector, string ko call-by-reference with a reference argument ki help se call karenge
2. int arr, char arr ko call-by-reference with a pointer argument ki help se call karenge
*/


int main() {
    // Calling vector with call-by-reference with a reference argument
    vector<int> v(5,0);
    pass(v);
    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Calling array with call-by-reference with a pointer argument
    int arr[] = {1,2,3,4,5};
    dob(arr);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calling vector with call-by-reference with a pointer argument
    vector<int> v1(5,0);
    pass1(&v1);
    for (int i = 0; i < 5; i++) {
        cout << v1[i] << " "; 
    }
    cout << endl;

    // Calling array with call-by-reference with a reference argument
    int arr1[] = {1,2,3,4,5};
    dob1(arr1);
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
}
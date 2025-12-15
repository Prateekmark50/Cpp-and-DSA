#include<iostream>
using namespace std;

class a{
    // int b;
    // int c;
    // int d;
    // char d;
};

int main(){
    a obj;
    cout << sizeof(obj) << " ";
}
/*
Here Padding concept is introduce. The Padding mainly tells us about memory allocation for variables that are aligned in sequence based on the size of the variable.
char a;
int b;
char c;
a p p p b b b b c p p p
Above show the space taken by data type and p denote padding

char c;
char d;
int b;
double e;
c d p p b b b b e e e e e e e e

Empty class size is 1
*/ 
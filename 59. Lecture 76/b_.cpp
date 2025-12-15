// Example 1
// #include<iostream>
// using namespace std;

// int main(){
//     int a, b;
//     cin >> a >> b;
//     int c = a/b;

//     cout << c << endl;
// }
// #include<iostream>
// using namespace std;

// int main(){
//     int a, b;
//     cin >> a >> b;

//     try{
//         if(b==0){
//             throw "Divide by 0 is not possible";
//         }
//         int c = a/b;
//         cout << c << endl;
//     }
//     catch(const char *e){
//         cout << "Exception Occured: " << e <<endl;
//     }
// }

// Example 2
#include<iostream>
#include<exception>
using namespace std;

int main(){
    try{
        int *p = new int[1000000000];
        cout << "Memory allocation is successfull\n";
        delete []p;
    }
    catch(const bad_alloc &e){
        cout << "Exception Occurred: " << e.what() << endl;
    }
}
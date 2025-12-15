// We can run in two ways: Iterative Approach and Recursive Approach
// 1. Iterative Approach 
/*
#include<iostream>
using namespace std;

int main(){
    int n = 5;
    // Iterative Approach
    for(int i = n; i > 0; i--) {
        cout << i << " days left for birthday\n";
    }
    cout << "Happy Birthday";
}
*/
// 2. Recursive Approach
// In three ways I have run this last one is best and easiest approach
/*
#include<iostream>
using namespace std;

void fun3(int n ) {
    cout << n << " days left for birthday\n";
}
void fun2(int n ) {
    cout << n << " days left for birthday\n";
}
void fun1(int n ) {
    cout << n << " days left for birthday\n";
}
void fun0(int n ) {
    cout <<"Happy Birthday\n";
}

int main(){
    int n = 3;
    fun3(3);
    fun2(2);
    fun1(1);
    fun0(0);
}
*/

/*
#include<iostream>
using namespace std;

void fun0(int n ) {
    cout <<"Happy Birthday\n";
}

void fun1(int n ) {
    cout << n << " days left for birthday\n";
    fun0(n-1);
}

void fun2(int n ) {
    cout << n << " days left for birthday\n";
    fun1(n-1);
}

void fun3(int n ) {
    cout << n << " days left for birthday\n";
    fun2(n-1);
}

int main(){
    int n = 3;
    fun3(3);
}
*/

#include<iostream>
using namespace std;

void fun3(int n ) {
    // Base Case
    if(n == 0){
        cout << "Happy Brithday";
        return;
    }
    cout << n << " days left for birthday\n";
    fun3(n-1);
}

int main(){
    int n = 8;
    fun3(n);
}

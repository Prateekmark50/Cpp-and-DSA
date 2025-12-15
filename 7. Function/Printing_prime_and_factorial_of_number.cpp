/*#include<iostream>
using namespace std;

bool Prime(int n){
    if(n<2)
    return 0;

    for(int i=2;i<n;i++){
            if(n%i==0)
            return 0;
    }
    return 1;
    
}

int Factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int a,b;
    cout<<"Enter the number:";
    cin>>a>>b;
    // A is Prime or not
    cout<<Prime(a)<<endl;
    // A ka Factorial
    cout<<Factorial(a)<<endl;
    // B is Prime or not
    cout<<Prime(b)<<endl;
    // B ka Factorial
    cout<<Factorial(b)<<endl;
    // B-A is Prime or not
    cout<<Prime(b-a)<<endl;
    // B-A ka Factorial
    cout<<Factorial(b-a)<<endl;
}*/
// OR

#include<iostream>
using namespace std;

void Prime(int n){
    if(n<2){
        cout<<0<<endl;
        return ;
    }
    

    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<0<<endl;
            return;
        }
    }
    cout<<1<<endl;
}

int Factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int a,b;
    cout<<"Enter the number:";
    cin>>a>>b;
    // A is Prime or not
    Prime(a);
    // A ka Factorial
    cout<<Factorial(a)<<endl;
    // B is Prime or not
    Prime(b);
    // B ka Factorial
    cout<<Factorial(b)<<endl;
    // B-A is Prime or not
    Prime(b-a);
    // B-A ka Factorial
    cout<<Factorial(b-a)<<endl;
}

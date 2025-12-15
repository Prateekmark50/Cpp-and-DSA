#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    for(int i=2;i<=num;i=i+2){
        cout<<i<<endl;
    }
}

// OR we can write like this also
/*
#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    for(int i=2;i<=num;i=i+1){
        if(i%2==0){
        cout<<i<<endl;
        }
    }
}
*/
#include<iostream>
using namespace std;
 int main(){
    int n, row, col;
    cout<<"Enter the number:";
    cin>>n;
    for(row=1;row<=n;row++){
        for(col=1;col<=n;col++){
            char name='a'+(row-1);
            cout<<name;
        }
        cout<<endl;
    }
 }
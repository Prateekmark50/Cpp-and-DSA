// GFG
// Print N-bit binary numbers having more 1s than 0s in all prefix
#include<iostream>
#include<vector>
using namespace std;

void find(int n, vector<string> &ans, string &temp, int zero, int one){
    if(temp.size() == n){
        ans.push_back(temp);
        return;
    }

    temp.push_back('1');
    find(n,ans,temp,zero,one+1);
    temp.pop_back();

    if(zero < one){
        temp.push_back('0');
        find(n,ans,temp,zero+1,one);
        temp.pop_back();
    }
}

int main(){
    int n;
    cout << "Enter the size of binary: ";
    cin >> n;
    vector<string> ans;
    string temp;
    find(n,ans,temp,0,0);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
/*
Example:-
We assume that I have taken 4 digit number
1111        1010
1           1
11          10
111         101
1111        1010

1001(wrong)
1
10
100
*/ 
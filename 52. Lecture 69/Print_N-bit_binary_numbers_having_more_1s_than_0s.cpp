/*
Print_N-bit_binary_numbers_having_more_1s_than_0s and there are some conditions:-
1. Start with 1
2. Overall number of 1's ≥ number of 0's (does not have to hold at every prefix).
*/ 
#include<iostream>
#include<vector>
using namespace std;

void find(int n, vector<string> &ans, string &temp, int zero, int one){
    if(temp.size() == n){
        if(one >= zero){
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back('1');
    find(n,ans,temp,zero,one+1);
    temp.pop_back();

    temp.push_back('0');
    find(n,ans,temp,zero+1,one);
    temp.pop_back();

}

int main(){
    int n;
    cout << "Enter the size of binary: ";
    cin >> n;
    vector<string> ans;
    string temp = "1";
    find(n,ans,temp,0,1);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
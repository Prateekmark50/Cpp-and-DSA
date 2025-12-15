/*
// Leetcode 
#include<iostream>
#include<vector>
using namespace std;

void permutation(int arr[], vector<vector<int> > &ans, vector<int> &temp, vector<bool> visited){
    // Base Condition
    if(visited.size() == temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int  i = 0; i < visited.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(arr[i]);
            permutation(arr,ans,temp,visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main(){
    int arr[] = {1,2,3};
    vector<vector<int> > ans;
    vector<int> temp;
    vector<bool> visited(3,0);
    permutation(arr,ans,temp,visited);

    for(int  i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}*/ 
/*
Time Complexity:-
    O(2^(n+1)-1) => O(2^n)
Space Complexity:-
    O(n)
*/ 

// METHOD 2
// This method is better the above one
#include<iostream>
#include<vector>
using namespace std;

void permutation(vector<int> arr, vector<vector<int> > &ans, int index){
    // Base Condition
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int  i = index; i < arr.size(); i++){
        swap(arr[index], arr[i]);
        permutation(arr,ans,index+1);
        swap(arr[index], arr[i]);
    }
}

int main(){
    vector<int> arr = {1,2,3};
    int index = 0;
    vector<vector<int> > ans;
    permutation(arr,ans,index);

    for(int  i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

#include<iostream>
#include<vector>
using namespace std;

void subSequence(int arr[], int index, int n, vector<vector<int> > &ans, vector<int> &temp, vector<int> &ans1, int sum){
    if(index == n){
        ans.push_back(temp);
        ans1.push_back(sum);
        return;
    }
    // Not included
    subSequence(arr,index+1,n,ans,temp,ans1,sum);
    // Included
    temp.push_back(arr[index]);
    subSequence(arr,index+1,n,ans,temp,ans1,sum+arr[index]);
    temp.pop_back();
}

int main(){
    int arr[] = {1,2,3,4};
    vector<vector<int> > ans;
    vector<int> ans1;
    vector<int> temp;
    subSequence(arr,0,4,ans,temp,ans1,0);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout <<"--> " << ans1[i];
        cout << endl;
    }
}
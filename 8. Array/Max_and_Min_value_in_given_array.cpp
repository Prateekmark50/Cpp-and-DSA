#include<iostream>
using namespace std;

int main()
{
    int arr[5]={2,3,1,7,8};
    // Min value in given array above 
    int ans = INT32_MAX;
    for(int i=0;i<5;i++){
        if(arr[i]<ans)
        ans = arr[i];
    }
    cout<<ans<<endl;

    // there is another way instead of using INT_MAX we can put first element of array 
    ans = arr[0];
    for(int i=0;i<5;i++){
        if(arr[i]<ans)
        ans = arr[i];
    }
    cout<<ans<<endl;

    // Max value in given array above
    ans = INT32_MIN;
    for(int i=0;i<5;i++){
        if(arr[i]>ans)
        ans = arr[i];
    }
    cout<<ans<<endl;
    return 0;//--> return 0 karna compulsary nahi hai but if we do it is a good habit while writting code
}
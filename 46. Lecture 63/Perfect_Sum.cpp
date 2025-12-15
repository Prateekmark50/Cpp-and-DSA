// This is the best code of Perfect Sum to handle if there is 0 also
#include<iostream>
using namespace std;

int subset(int arr[], int index, int n, int sum){
    if(index == n){
        if(sum == 0){   // Instead of if else we directly write {return sum ==0;}
            return 1;
        }
        else{
            return 0;
        }
    }
    return subset(arr, index+1, n, sum) + subset(arr, index+1, n, sum-arr[index]);
}

int main(){
    int arr[] = {5, 2, 3, 6, 10, 8};
    int sum = 19;
    cout <<"Number of subsets with sum " << sum << " is: " << subset(arr,0,6,sum) << endl; 
}
/*
Time Complexity:-
    O(2^(n+1)-1) => O(2^n)
Space Complexity:-
    O(n)
*/ 
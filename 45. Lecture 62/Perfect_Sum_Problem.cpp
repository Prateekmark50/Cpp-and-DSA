#include<iostream>
using namespace std;

void find(int arr[], int index, int n, int target, int &count){
    if(target == 0){
        count++;
        return;
    }
    if(index == n || target < 0){
        return;
    }

    // Don't include current element
    find(arr, index + 1, n, target, count);

    // Include current element
    find(arr, index + 1, n, target - arr[index], count);
}

int main(){
    int arr[] = {5, 2, 3, 6, 10, 8};
    int target = 19;
    int count = 0;

    find(arr, 0, 6, target, count);

    cout << "Number of subsets with sum " << target << " is: " << count << endl;
    return 0;
}
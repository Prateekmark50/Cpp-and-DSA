#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    vector<int> temp(end-start+1);
    int left = start, right = mid+1, index = 0;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index] = arr[left];
            left++, index++;
        }
        else{
            temp[index] = arr[right];
            right++, index++;
        }
    }

    // Left array is not empty yet
    while(left <= mid){
        temp[index] = arr[left];
        left++, index++;
    }

    // Right array is not empty yet
    while(right <= end){
        temp[index] = arr[right];
        right++, index++;
    }

    // Put these value in array from temp
    index = 0;
    while(start <= end){
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergeSort(int arr[], int start, int end){
    if(start == end){
        return;
    }
    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid); // Left Side
    mergeSort(arr, mid+1, end); // Right Side
    merge(arr, start, mid, end);
}

int main(){
    int arr[] = {6,3,1,2,8,9,10,7,3,10};
    int n = 10;
    cout << "Before Sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr,0,n-1);
    cout << "After Sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
/*
Time Complexity:-
    Worst Case: O(n*log n)
Space Complexity:-
    Worst Case: O(n)
*/
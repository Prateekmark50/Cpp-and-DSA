#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int position = start;
    for(int i = start; i <= end; i++){
        if(arr[i] <= arr[end]){
            swap(arr[i], arr[position]);
            position++;
        }
    }
    return position-1;
}

void quickSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1); //Left Side
    quickSort(arr,pivot+1,end); //Right Side
}

int main(){
    int arr[] = {6,3,1,2,8,9,10,7,3,10};
    int n = 10;
    cout << "Before Sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr,0,n-1);
    cout << "After Sorting: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

/*
Time Complexity:-
    Average Case: O(n*log n)
    Worst Case: O(n^2)
Space Complexity:-
    Average Case: O(log n)
    Worst Case: O(n)
*/
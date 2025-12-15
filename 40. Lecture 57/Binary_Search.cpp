#include<iostream>
using namespace std;

bool binarySearch(int arr[], int X, int start, int end){
    // Base Case
    if(start>end){
        return 0;
    }
    int mid = start+(end-start)/2;
    if(arr[mid] == X){
        return 1;
    }
    else if(arr[mid] < X){
        return binarySearch(arr, X, mid+1, end);
    }
    else{
        return binarySearch(arr, X, start, mid-1);
    }
}

int main(){
    int arr[] = {2,4,6,8,10,12};
    int X = 10;
    cout << binarySearch(arr, X, 0,5);
}
/*// GFG
// If we have to return the index of element then we write the below code
#include<iostream>
using namespace std;

int binarySearch(int arr[], int X, int start, int end){
    // Base Case
    if(start>end){
        return -1;
    }
    int mid = start+(end-start)/2;
    if(arr[mid] == X){
        return 1;
    }
    else if(arr[mid] < X){
        return binarySearch(arr, X, mid+1, end);
    }
    else{
        return binarySearch(arr, X, start, mid-1);
    }
}

int searchInSorted(int arr[], int N, int X){
    return binarySearch(arr, X, 0, N-1);
}

int main(){
    int arr[] = {2,4,6,8,10,12};
    int X = 10;
    cout << searchInSorted(arr, 6, X);
}
*/
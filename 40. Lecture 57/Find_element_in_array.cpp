#include<iostream>
using namespace std;

bool linearSearch(int arr[], int X, int index, int size){
    // Base Case
    if(index == 6){
        return 0;
    }
    if(arr[index] == X){
        return 1;
    }
    return linearSearch(arr, X, index+1, 6);
}

int main(){
    // Linear Search
    int arr[] = {2,3,6,7,1,5};
    int X = 7;
    cout << linearSearch(arr,X,0,6) <<endl;
}
/*
// GFG
// If we have to return the index of element then we write the below code
#include<iostream>
using namespace std;

int linearSearch(int arr[], int X, int index, int N){
    // Base Case
    if(index == N){
        return -1;
    }
    if(arr[index] == X){
        return index;;
    }
    return linearSearch(arr, X, index+1, N);
}

int search(int arr[], int N, int X){
    return linearSearch(arr, X, 0, N);
}

int main(){
    int arr[] = {2,4,6,8,10,12};
    int X = 10;
    cout << search(arr, 6, X);
}
*/
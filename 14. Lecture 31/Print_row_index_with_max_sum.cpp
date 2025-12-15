#include<iostream>
using namespace std;

void printRowSumMax(int arr[][4], int row, int col){
    int index = -1, sum = INT32_MIN;
    for(int i=0; i<row; i++){
        int total = 0;
        for(int j=0; j<col; j++){
            total += arr[i][j];
            if(total>sum){
                sum = total;
                index = i;
            }
        }
    }
    cout<<"The row index with maximum sum is: "<<index<<endl;
}

int main(){
    int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2[3][4] = {0,1,3,4,6,7,10,11,41,18,9,11};
    printRowSumMax(arr1, 3, 4);
    printRowSumMax(arr2, 3, 4);
}
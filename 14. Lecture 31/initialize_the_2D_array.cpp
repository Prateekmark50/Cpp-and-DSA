#include<iostream>
using namespace std;

void printcol(int arr[][4], int row, int col){
    for(int j=0; j<col; j++){
        for(int i=0; i<row; i++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    // Create 2D array
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    // Print all the value in array row wise
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout<<arr[row][col]<<" ";
        }
    }
    cout<<endl;

    // Print all the value in array column wise
    for(int col=0; col<4; col++){
        for(int row=0; row<3; row++){
            cout<<arr[row][col]<<" ";
        }
    }
    cout<<endl;

    // Print all the value in array column wise using function call
    printcol(arr,3,4);

    // Update the value in array
    arr[0][0] = 13;
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout<<arr[row][col]<<" ";
        }
    }
    cout<<endl;

    // To print any specific row from arr[3][4]
    for(int j=0; j<4; j++)
    cout<<arr[0][j]<<" ";
}
#include<iostream>
using namespace std;

void printSumDiagonal(int matrix[][3], int row, int col){
    int first_sum = 0;
    int second_sum = 0;
    // first diagonal sum
    int i=0;
    while(i<row){
        first_sum += matrix[i][i];
        i++;
    }
    // second diagonal sum
    i = 0; int j=col-1;
    while(j>=0){
        second_sum += matrix[i][j];
        i++, j--;
    }
    cout<<first_sum<<" "<<second_sum;
}

int main(){
    
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};// row and column should be equal for diagonal sum
    printSumDiagonal(matrix, 3, 3);
}
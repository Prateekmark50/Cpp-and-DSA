#include <iostream>
#include <vector>
using namespace std;

// Method1:
void rotateMatrix1(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++){
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }

    // Transpose the matrix again
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row again
    for(int i = 0; i < n; i++){
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }

    // Print the rotated matrix
    cout << "The rotaed 180 degree (clockwise) matrix using method 1 is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Method2:
void rotateMatrix2(vector<vector<int>>& matrix){
    int n = matrix.size();

    // Reverse each column
    for(int j = 0; j < n; j++){
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[start][j], matrix[end][j]);
            start++, end--;
        }
    }

    // Reverse each row
    for(int i = 0; i < n; i++){
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }

    // Print the rotated matrix
    cout << "The rotated 180 degree (clockwise) matrix using method 2 is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (N): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the original matrix
    cout << "The original matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotate the matrix by 90 degree clockwise
    rotateMatrix1(matrix); // Method 1
    rotateMatrix2(matrix); // Method 2

    return 0;
}
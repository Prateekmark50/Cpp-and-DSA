#include <iostream>
#include <vector>
using namespace std;

void rotate90degree(vector<vector<int>>& matrix){
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

    int K;
    cout << "Enter the number of times you want to rotate the matrix: ";
    cin>>K;
    K = K % 4;

    // Print the original matrix
    cout << "The original matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotate the matrix by K times
    while (K) {
        rotate90degree(matrix);
        K--;
    }

    // Print the rotated matrix
    cout << "The rotated K times (clockwise) matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
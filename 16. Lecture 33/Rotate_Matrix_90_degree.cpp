#include <iostream>
#include <vector>
using namespace std;
// Method 1: Brute Force Approach
void rotateMatrix1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));

    // Brute force approach to rotate the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    // Print the ans matrix
    cout << "The rotaed 90 degree (clockwise) matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
// Method 2: Best Approach by making changes in the given matrix which help to reduce space complexity to O(1)
void rotateMatrix2(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Best approach to transpose the matrix
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

    // Print the rotated matrix
    cout << "The rotated 90 degree (clockwise) matrix is: " << endl;
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
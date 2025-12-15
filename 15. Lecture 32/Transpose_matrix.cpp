#include <iostream>
#include <vector>
using namespace std;

void transposeMatrix(vector<vector<int>>& matrix, int n) {
    vector<vector<int>> transposed(n, vector<int>(n));

    // Brute force approach to transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    cout << "The transposed matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transposed[i][j] << " ";
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

    // Transpose the matrix
    transposeMatrix(matrix, n);

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// void transposeMatrix(vector<vector<int>>& matrix) {
//     int row = matrix.size(), col = matrix[0].size();
//     vector<vector<int>> ans(col, vector<int>(row));  // Initialize ans with the correct dimensions

//     // Transpose the matrix
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             ans[j][i] = matrix[i][j];
//         }
//     }

//     // Print the transposed matrix
//     cout << "The transpose of the matrix is: " << endl;
//     for (int i = 0; i < col; i++) {  // Use the dimensions of the transposed matrix
//         for (int j = 0; j < row; j++) {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     int n, m;
//     cout << "Enter the size of row and column: ";
//     cin >> n >> m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     cout << "Enter the elements of the matrix: " << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     transposeMatrix(matrix);
//     return 0;
// }

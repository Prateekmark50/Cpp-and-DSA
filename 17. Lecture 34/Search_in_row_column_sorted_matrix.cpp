#include <iostream>
#include <vector>
using namespace std;

// Method 1: Start searching from top right corner [0][m-1]
bool search(vector<vector<int> > matrix, int n, int m, int x){
    int row = 0, col = m - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == x)
        return 1;
        else if (matrix[row][col] < x)
        row++;
        else
        col--;
    }
    return 0;
}

// Method 2: Start searching from bottom left corner [n-1][0]
bool search2(vector<vector<int> > matrix, int n, int m, int x) {
    int i = n - 1, j = 0;
    while (i >= 0 && j < m) {
        if (matrix[i][j] == x)
        return 1;
        else if (matrix[i][j] < x)
        j++;
        else
        i--;
    }
    return 0;
}

int main(){
    int m, n;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int x;
    cout << "Enter the target (x): ";
    cin >> x;

    cout << search(matrix, n, m, x)<< endl; // Method 1
    cout << search2(matrix, n, m, x); // Method 2
}
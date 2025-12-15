#include <iostream>
#include <vector>
using namespace std;

// Method 1: Brute Force Approach
bool searchMatrix1(vector<vector<int> >& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == target)
            return 1;
        }
    }
    return 0;
}

// Method 2: First check the target lie in which row and then we apply binary search on that row 
bool searchMatrix2(vector<vector<int> >& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
            int start = 0, end = n - 1;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (matrix[i][mid] == target)
                return 1;
                else if (matrix[i][mid] < target)
                start = mid + 1;
                else // matrix[i][mid] > target
                end = mid - 1;
            }
        }
    }
    return 0;
}

// Method 3: In this we apply binary search from [0][0] to [n*m - 1] 
bool searchMatrix3(vector<vector<int> >& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int start = 0, end = (n * m) - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int row_index = mid / m;
        int col_index = mid % m;
        if (matrix[row_index][col_index] == target)
        return 1;
        else if (matrix[row_index][col_index] < target)
        start = mid + 1;
        else
        end  = mid - 1;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    cout << searchMatrix1(matrix, target) << endl; // Method 1
    cout << searchMatrix2(matrix, target) << endl; // Method 2
    cout << searchMatrix3(matrix, target) << endl; // Method 3
}
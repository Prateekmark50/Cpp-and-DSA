#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, right = col - 1, left = 0, bottom = row - 1;
    while (top <= bottom && left <= right) {

        // Print top
        for (int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        // Print right
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // Print bottom
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Print left
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> spiral = spiralOrder(matrix);

    cout << "The spiral order of the matrix is: ";
    for(int i = 0; i < spiral.size(); i++){
        cout<< spiral[i] << " ";
    }
    // We can write like this also to print the spiral
    // for (int i : spiral) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // return 0;
}

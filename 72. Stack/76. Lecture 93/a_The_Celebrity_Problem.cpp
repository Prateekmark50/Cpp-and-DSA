// GFG:- The Celebrity Problem
// Link:- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category=Stack&sortBy=submissions

/*
Examples:

Input: mat[][] = [[1, 1, 0],
                [0, 1, 0],
                [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.

Input: mat[][] = [[1, 1], 
                [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

Input: mat[][] = [[1]]
Output: 0
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> st;
    for (int  i = n-1; i >= 0; i--) {
        st.push(i);
    }


    int first, second;
    while (st.size() > 1) {
        first = st.top();
        st.pop();

        second = st.top();
        st.pop();

        if (mat[first][second] && !mat[second][first]) {
            st.push(second);
        }
        else if (!mat[first][second] && mat[second][first]) {
            st.push(first);
        }
    }

    if (st.empty()) {
        return -1;
    }

    int num = st.top();
    st.pop();
        
    // Celebrity hai ya nahi
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        row += mat[num][i];
        col += mat[i][num];
    }

    return row==1 && col==n ? num : -1;
}

int main() {
    int n;
    cout << "Enter number of people (n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    cout << "Enter the matrix (" << n << "x" << n << ") where mat[i][j] = 1 if person i knows person j, else 0:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = celebrity(mat);

    if (ans == -1)
        cout << "No celebrity found." << endl;
    else
        cout << "Celebrity is person " << ans << "." << endl;
}
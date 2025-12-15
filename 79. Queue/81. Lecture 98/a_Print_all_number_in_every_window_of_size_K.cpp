/*
Example 1:

Input: arr = [2,3,1,5,6,7,8], k = 3
Output: 2 3 1
        3 1 5
        1 5 6
        5 6 7
        6 7 8
*/ 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the element of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the window size (k) : ";
    cin >> k;
    
    queue<int> q;
    // k-1 elements ko push kardo queue ke andar
    for (int  i = 0; i < k-1; i++) {
        q.push(arr[i]);
    }

    for (int i = k-1; i < n; i++) {
        q.push(arr[i]);
        display(q);
        q.pop();
    }

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
    
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findTwoElement(arr, n);
}
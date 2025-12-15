#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;

int maxDiff(vector<int>& arr, int n) {
    if (n < 2) return 0; // Edge case: if the array has less than 2 elements, return 0

    vector<int> suffix(n);
    suffix[n-1] = arr[n-1];
    
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    cout<<"The suffix array: ";
    for(int i = 0; i < n; i++){
        cout<<suffix[i]<<" ";
    }
    cout<<endl;

    int max_diff = INT32_MIN;
    for (int i = 0; i < n-1; i++) {
        max_diff = max(max_diff, suffix[i+1] - arr[i]);
    }

    return max_diff;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "The maximum difference between two elements is: " << maxDiff(arr, n) << endl;
    return 0;
}
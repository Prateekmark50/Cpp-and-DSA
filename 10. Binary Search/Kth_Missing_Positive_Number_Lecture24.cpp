#include <iostream>
#include <vector>
using namespace std;

int KthMissingPositiveNumber (vector<int> &arr, int target) {
    int n = arr.size();
    int start = 0, end = n - 1, ans = arr.size();
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (arr[mid] - mid - 1 >= target){
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans + target;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target: ";
    cin >> target;

    cout << "K-th missing positive number is: " << KthMissingPositiveNumber(arr, target);
}
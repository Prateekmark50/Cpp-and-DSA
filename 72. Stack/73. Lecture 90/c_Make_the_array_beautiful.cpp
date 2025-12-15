// GFG :-Make the array beautiful
// Link:- https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

/*
Example 1:

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.

Example 2:

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. 
*/ 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
        }
        // Non Negative Number
        else if (arr[i] >= 0)
        {
            // Non Negative Number
            if (s.top() >= 0)
            {
                s.push(arr[i]);
            }
            // Negative Number
            else
            {
                s.pop();
            }
        }
        // Negative Number
        else
        {
            // Negative Number
           if (s.top() < 0)
            {
                s.push(arr[i]);
            }
            // Non Negative Number
            else
            {
                s.pop();
            } 
        }
    }

    // Transfer stack elements to vector in correct order
    vector<int> ans(s.size());
    int i = s.size()-1;
    while (!s.empty()) {
        ans[i] = s.top();
        i--;
        s.pop();
    }
        
    return ans;
}

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> result = makeBeautiful(arr);
    
    cout << "The beautiful array is:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
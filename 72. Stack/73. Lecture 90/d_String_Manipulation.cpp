// GFG :- String Manipulation
// Link:- https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

/*
Examples:

Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
Output: 3
Explanation: After the first iteration, we'll have: ab bcd ab. We can't further destroy more strings and hence we stop and the result is 3. 

Input: arr[] = ["tom", "jerry", "jerry", "tom"]
Output: 0
Explanation: After the first iteration, we'll have: tom tom. After the second iteration: 'empty-array' .Hence, the result is 0.
*/ 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int removeConsecutiveSame(vector<string>& arr) {
    stack<string> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
        }
        // String is repeated in array
        else if (arr[i] == s.top())
        {
            s.pop();
        }
        // String is not repeated
        else
        {
            s.push(arr[i]);
        }
    }
        
    return s.size();
}

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<string> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = removeConsecutiveSame(arr);
    
    cout << "The number of word left is: " << result << endl;
}

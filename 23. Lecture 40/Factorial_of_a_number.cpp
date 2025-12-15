#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> factorial(int N) {
    vector<int> ans(1,1);
    while (N>1) {
        int carry = 0, res, size = ans.size();
        for (int i = 0; i < size; i++) {
            res = ans[i] * N + carry;
            ans[i] = res % 10;
            carry = res / 10;
        }
        while (carry) {
            ans.push_back (carry % 10);
            carry /= 10;
        }
        N--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int N;
    cout << "Enter the number: ";
    cin >> N;
    vector<int> fac = factorial(N);
    cout << "Factorial of " << N << " is: ";
    for (int i = 0; i < fac.size(); i++) {
        cout << fac[i];
    }
    cout << endl;
    return 0;
}
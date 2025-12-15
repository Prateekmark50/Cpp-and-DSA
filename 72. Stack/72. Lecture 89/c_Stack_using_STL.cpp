#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> S;
    S.push(6);
    S.push(16);
    S.push(26);
    cout << S.size() << endl;

    // pop
    S.pop();

    // top
    cout << S.top() << endl;

    // empty
    cout << S.empty() << endl;
}
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int > d;
    d.push_back(10);
    d.push_front(30);
    cout << d.front() << endl;
    d.pop_front();
    cout << d.front() << endl;
}
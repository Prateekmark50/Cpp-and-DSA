#include<iostream>
using namespace std;

// Recursive function to check for prime
bool isPrime(int n, int i = 2) {
    // Base cases
    if (n <= 2) {
        return (n == 2);  // 2 is prime, 0 and 1 are not
    }
    if (n % i == 0) {
        return false;     // divisible => not prime
    }
    if (i * i > n) {
        return true;      // no divisor found till √n => prime
    }

    // Recursive call
    return isPrime(n, i + 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is a Prime Number." << endl;
    } else {
        cout << n << " is Not a Prime Number." << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

// Recursive Fibonacci
unsigned long long fibRecursive(int n) {
    if (n <= 1)
        return n;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-recursive Fibonacci
unsigned long long fibIterative(int n) {
    if (n <= 1)
        return n;

    unsigned long long a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    cout << "Enter n (0-93): ";

    if (!(cin >> n) || n < 0 || n > 93) {
        cout << "Invalid input. Enter an integer from 0 to 93.\n";
        return 1;
    }

    cout << "Recursive Fibonacci: "
         << fibRecursive(n) << endl;

    cout << "Non-recursive Fibonacci: "
         << fibIterative(n) << endl;

    return 0;
}

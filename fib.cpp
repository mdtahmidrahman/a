#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the position of the Fibonacci sequence: ";
    int n; cin >> n;

    int fib[n + 1];
    fib[0] = 0; fib[1] = 1; fib[2] = 1;

    cout << "Fibonacci sequence up to term " << n << ": " << fib[0] << " " << fib[1] << " " << fib[2] << " ";

    for (int i = 3; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << " ";
    }cout << endl;
    cout << "Fibonacci number at position " << n << " is: " << fib[n] << endl;

    return 0;
}

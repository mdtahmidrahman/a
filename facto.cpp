#include <iostream>
using namespace std;
int main()
{
    cout << "Enter a number: ";
    int n; cin >> n;

    int factorial[n + 1];
    factorial[0] = 1;

    for(int i = 1; i <= n; i++) factorial[i] = i * factorial[i - 1];

    cout << "Factorial of " << n << " is: " << factorial[n] << endl;
    return 0;
}

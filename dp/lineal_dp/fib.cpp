#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long fib1 = 1;
    long long  fib2 = 1;
    for (int i = 0; i < n; ++i)
    {
        long long temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp; 
    }
    cout << fib2 << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int fib1 = 0;
    int fib2 = 1;
    for (int i = 0; i < n; ++i)
    {
        int temp = fib2;
        fib2 = (fib1 + fib2) % 1000003;
        fib1 = temp;
    }
    cout << fib2 << endl;
    return 0;
}

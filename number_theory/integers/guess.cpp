#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long i = 18446744073709551615ull;
    unsigned long long x;
    cin >> x;
    if (x % 3 == 0)
        cout << x / 3 << endl;
    else if (x % 3 == 1)
    {
        unsigned long long x1 = i / 3 * 2 + x / 3 + 1; // X = (2^64 - 1) / 3 * 2  + r / 3 + (1 + 1 + 1) / 3 
        cout << x1 << endl;
    }
    else if (x % 3 == 2)
    {
        unsigned long long x2 = i / 3 + x / 3 + 1; // (2^64 - 1) / 3 + r / 3 + (2 + 1) / 3 
        cout << x2 << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    int mod = 1000007;
    cin >> a >> b;
    cout << ((a * a - b * b) % mod + mod) % mod;
    return 0;
}

#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ull a, b;
    cin >> a >> b;
    ull gc = gcd(a, b); 
    // как проверить что a * b / gc > 1e18, если 0 <= a, b <= 1e18
    ull noc = (a / gc) * b;
    if (noc > 1e18)
        cout << -1 << endl;
    else
        cout << noc << endl;
    return 0;
}

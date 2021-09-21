#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % gcd(a, b) == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}

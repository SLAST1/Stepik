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
    int n;
    cin >> n;
    int x;
    cin >> x;
    for (int i = 1; i < n; ++i)
    {
        int t;
        cin >> t;
        x = gcd(x, t);
    }
    cout << x << endl;
    return 0;
}

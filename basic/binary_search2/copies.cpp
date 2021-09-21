#include <iostream>

using namespace std;

long long solve(long long x, long long y, long long n)
{
    long long l = 0;
    long long r = (n - 1) * max(x, y);
    long long start = min(x, y);
    while (l + 1 < r)
    {
        long long m = (l + r) / 2;
        if (m / x + m / y >= n - 1)
            r = m;
        else
            l = m;
    }
    return r + start;
}

int main()
{
    long long n, x, y;
    cin >> n >> x >> y;
    cout << solve(x, y, n) << endl;
    return 0;
}

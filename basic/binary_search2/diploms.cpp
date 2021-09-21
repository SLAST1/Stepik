#include <iostream>

using namespace std;

long long diplomnumber(long long w, long long h, long long mid)
{
    return (mid / w) * (mid / h);
}

long long solve(long long w, long long h, long long n)
{
    long long  l = 0;
    long long  r = max(w, h) * n;
    while (l + 1 < r)
    {
        long long mid = (l + r) / 2; 
        if (diplomnumber(w, h, mid) < n)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main()
{
    long long w, h, n;
    cin >> w >> h >> n;
    cout << solve(w, h, n) << endl;
    return 0;
}

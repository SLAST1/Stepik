#include <iostream>

using namespace std;

long long norm(long long d, long long MOD)
{
    return ((d % MOD) + MOD) % MOD;
}

long long Madd(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) + norm(y, MOD), MOD);
}

long long Msub(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) - norm(y, MOD), MOD);
}

long long Mmul(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) * norm(y, MOD), MOD);
}

int main()
{
    int n;
    cin >> n;
    int mod = 1000003;
    int ans = 1;
    if (n > mod)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i <= n; ++i)
        ans = Mmul(ans, i, mod);
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = a[0];
    for (int i = 1; i <= n; ++i)
    {
        if (i < 3)
            dp[i] = dp[i - 1];
        else
            dp[i] = max(dp[i - 1], dp[i - 3]);
        if (i > 4)
            dp[i] = max(dp[i], dp[i - 5]);
        dp[i] += a[i - 1];
    }
    cout << dp[n] << endl;
}

int main()
{
    int t = 1;
    forn(tt, t)
        solve();
    return 0;
}


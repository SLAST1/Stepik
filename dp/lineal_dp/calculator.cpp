#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;

    int dp[n + 1];
    dp[1] = 0;
    for (int i = 2; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1];
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2]);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3]);
        ++dp[i];
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


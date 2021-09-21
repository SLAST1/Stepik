#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    char a[n];
    forn (i, n)
        cin >> a[i];
    
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = (a[0] == '0' ? 1 : 0);
    dp[2] = (a[1] == '0' ? dp[0] + dp[1] : 0);
    for (int i = 3; i < n + 1; ++i)
    {
        if (a[i - 1] == '1')
            dp[i] = 0;
        else
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            dp[i] = (dp[i] + dp[i - 3]) % mod;
        }
    }
    cout << dp[n] % mod << endl;
}

int main()
{
    int t = 1;
    forn(tt, t)
        solve();
    return 0;
}


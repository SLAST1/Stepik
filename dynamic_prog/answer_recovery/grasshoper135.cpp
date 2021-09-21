#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
    vector<int> coords;
    int i = n;
    while (i > 0)
    {
        coords.push_back(i);
        long long diff = dp[i] - a[i - 1]; 
        if (i >= 5 && diff == dp[i - 5])
            i -= 5;
        else if (i >= 3 && diff == dp[i - 3])
            i -= 3;
        else if (i >= 1 && diff == dp[i - 1])
            --i;
    }
    cout << dp[n] << " " << coords.size() << endl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i] << " ";
    cout << endl;
}

int main()
{
    int t = 1;
    forn(tt, t)
        solve();
    return 0;
}


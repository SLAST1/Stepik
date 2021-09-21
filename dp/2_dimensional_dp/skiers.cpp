#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dp(n);
    dp[0].resize(1);
    cin >> dp[0][0];
    for (int i = 0; i < n - 1; ++i)
    {
        dp[i + 1].resize(i + 2);
        for (int& j : dp[i + 1])
            cin >> j;
    }

    for (int i = 1; i < n; ++i)
        dp[i][0] += dp[i - 1][0];

    for (int i = 1; i < n; ++i)
        dp[i][dp[i].size() - 1] += dp[i - 1][dp[i - 1].size() - 1];

    for (int i = 2; i < n; ++i)
        for (int j = 1; j < dp[i].size() - 1; ++j)
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);

    cout << *max_element(begin(dp[n - 1]), end(dp[n - 1])) << nl;
    return 0;
}


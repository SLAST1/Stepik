#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define f0rn(i, a, n) for (int i = a; i < n; ++i)

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long > vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;

const char nl = '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vvl a(n, vl(m));

    for (auto& i : a)
        for (auto& j : i)
            cin >> j;

    vvl dp(n + 1, vl(m + 1));

    f0rn(i, 1, m + 1)
        dp[0][i] = 1000001;
    f0rn(i, 1, n + 1)
        dp[i][0] = 1000001;

    f0rn(i, 1, n + 1)
        f0rn(j, 1, m + 1)
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + a[i - 1][j - 1];

    int i = n, j = m;
    vector<pair<int, int>> coords;
    while (i > 0 && j > 0)
    {
        coords.push_back(make_pair(i, j)); 
        int diff = dp[i][j] - a[i - 1][j - 1];
        if (diff == dp[i - 1][j - 1])
        {
            --i;
            --j;
        }
        else if (diff == dp[i - 1][j])
            --i;
        else if (diff == dp[i][j - 1])
            --j;
    }
    
    cout << dp[n][m] << " " << coords.size() << nl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i].first << " " << coords[i].second << nl;
    return 0;
}


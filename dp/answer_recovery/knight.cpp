#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define f0rn(i, a, n) for (int i = a; i < n; ++i)


typedef long long ll;
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long > vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;

const char nl = '\n';
long long inf = 1e18;

void dp_min(int i, int j, int n, int m, vvl& dp)
{
    if (i - 2 >= 0 && j - 1 >= 0)
        dp[i][j] = min(dp[i][j], dp[i - 2][j - 1]);
    if (i - 2 >= 0 && j + 1 < m)
        dp[i][j] = min(dp[i][j], dp[i - 2][j + 1]);
    if (i - 1 >= 0 && j - 2 >= 0)
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 2]);
    if (i + 1 < n && j - 2 >= 0)
        dp[i][j] = min(dp[i][j], dp[i + 1][j - 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // input
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (auto& i : a)
        for (auto& j : i)
            cin >> j;

    // dp
    vvl dp(n, vl(m, inf));
    for (int k = 0; k < m; ++k)
    {
        int i = 0;
        int j = k; 
        while (j >= 0 && i < n)
        {
            dp_min(i, j, n, m, dp);
            if (dp[i][j] != inf)
                dp[i][j] += a[i][j];
            if (i == 0 && j == 0)
                dp[0][0] = a[0][0];
            ++i;
            --j;
        }
    }

    for (int k = 1; k < n; ++k)
    {
        int i = k;
        int j = m - 1; 
        while (j >= 0 && i < n)
        {
            dp_min(i, j, n, m, dp);
            if (dp[i][j] != inf)
                dp[i][j] += a[i][j];
            ++i;
            --j;
        }
    }
    
    if (dp[n - 1][m - 1] == inf)
    {
        cout << "NO" << nl;
        return 0;
    }

    // recovery
    vector<pair<ll, ll>> coords;
    int i = n - 1, j = m - 1;
    while (true)
    {
        coords.push_back(make_pair(i, j));
        if (i == 0 && j == 0 || i < 0 || j < 0)
            break;
        ll diff = dp[i][j] - a[i][j];
        if (i - 2 >= 0 && j - 1 >= 0 && diff == dp[i - 2][j - 1]) {
            i -= 2;
            --j;
        }
        else if (i - 2 >= 0 && j + 1 < m && diff == dp[i - 2][j + 1]) {
            i -= 2;
            ++j;
        }
        else if (i - 1 >= 0 && j - 2 >= 0 && diff == dp[i - 1][j - 2]) {
            --i;
            j -= 2;
        }
        else if (i + 1 < n && j - 2 >= 0 && diff == dp[i + 1][j - 2]) {
            ++i;
            j -= 2;
        }
    }
   
    // print 
    cout << "YES" << nl;
    cout << dp[n - 1][m - 1] << " " << coords.size() << nl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i].first + 1 << " " << coords[i].second + 1 << nl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>

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

ll inf = -1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int s, n;
    cin >> s >> n;
    vector<int> w(n);
    for (auto& i : w)
        cin >> i;
    vector<int> c(n);
    for (auto& i : c)
        cin >> i;

    vvl dp(n + 1, vl(s + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + c[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << *max_element(begin(dp[n]), end(dp[n])) << " ";
    int ans = max_element(begin(dp[n]), end(dp[n])) - begin(dp[n]);
    vector<int> coords;
    int i = n;
    while (i > 0)
    {
        if (ans >= w[i - 1] && dp[i - 1][ans - w[i - 1]] + c[i - 1] == dp[i][ans])
        {
            coords.push_back(i);
            ans -= w[i - 1];
        }
        --i;
    }
    
    cout << coords.size() << nl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i] << " ";
    cout << nl;
    return 0;
}

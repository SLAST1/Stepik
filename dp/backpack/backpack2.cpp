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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int s, n;
    cin >> s >> n;
    vector<int> w(n);
    for (auto& i : w)
        cin >> i;

    vvi dp(n + 1, vi(s + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= s; ++j)
        {
            if (w[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = s; i >= 0; --i)
    {
        if (dp[n][i] == 1)
        {
            cout << i << nl;
            break;
        }
    }
    return 0;
}

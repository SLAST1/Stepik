#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

const char nl = '\n';
int mod = 1e9 + 7;

ostream& operator<<(ostream& out, const pair<int, int>& p)
{
    out << "[" << p.first << " " << p.second << "]";
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vvi dp(n + 1, vi (m + 1, 0));
    vvi dp1(n + 1, vi (m + 1, 0));
    vvi dp2(n + 1, vi (m + 1, 0));
    vvi dp3(n + 1, vi (m + 1, 0));

    // dp 
    dp1[1][1] = 1;
    dp2[1][1] = 1;
    dp3[1][1] = 1;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = ((dp1[i][j - 1] + dp2[i - 1][j]) % mod + dp3[i - 1][j - 1]) % mod;
                dp1[i][j] = (dp[i][j] + dp1[i][j - 1]) % mod;
                dp2[i][j] = (dp[i][j] + dp2[i - 1][j]) % mod;
                dp3[i][j] = (dp[i][j] + dp3[i - 1][j - 1]) % mod;
            }
        }
    } 
    
    // print 
    cout << dp[n][m] << nl; 
    return 0;
}

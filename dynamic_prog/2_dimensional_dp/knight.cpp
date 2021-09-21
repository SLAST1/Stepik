#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const char nl = '\n';
int nn, mm;
int mod = 1e9 + 123;

int solve(int n, int m, vector<vector<int>>& dp)
{
    if (n < 0 || m < 0 || n > nn - 1 || m > mm - 1)
        return 0;

    if (n == 0 && m == 0)
        return 1;    

    if (dp[n][m] != -1)
        return dp[n][m];
    

    dp[n][m] = (solve(n - 2, m + 1, dp) + solve(n - 2, m - 1, dp)) % mod;
    dp[n][m] = (dp[n][m] + solve(n - 1, m - 2, dp)) % mod;
    dp[n][m] = (dp[n][m] + solve(n + 1, m - 2, dp)) % mod;
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    nn = n;
    mm = m;
 
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    cout << solve(n - 1, m - 1, dp) << nl;
        
    return 0;
}


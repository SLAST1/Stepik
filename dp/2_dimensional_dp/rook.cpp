#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const char nl = '\n';
int mod = 1e9 + 33;

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
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (m + 1, make_pair(0, 0)));
    
    // dp 
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (i == 1 && j == 1)
                dp[i][j] = make_pair(1, 1);
            else
            {
                int temp = (dp[i][j - 1].first + dp[i - 1][j].second) % mod;
                dp[i][j] = make_pair((temp + dp[i][j - 1].first) % mod,
                    (temp + dp[i - 1][j].second) % mod);
            }
        }
    } 
    
//    forn(i, n)
//    {
//        forn(j, m)
//            cout << dp[i][j] << " ";
//        cout << nl;
//    } 
   
    // print 
    cout << ((dp[n][m].first - dp[n][m - 1].first) % mod + mod) % mod << nl;
    return 0;
}


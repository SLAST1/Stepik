#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, mod = 1000000009;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int> (m));
 
    for (auto& i : table)
        for (int& j : i)
            cin >> j; 

    vector<vector<int>> dp(n, vector<int> (m));
    
    int i = 0;
    while(i < m && table[0][i] == 0)
        dp[0][i++] = 1;
    while (i < m)
        dp[0][i++] = 0;
    
    i = 0;
    while(i < n && table[i][0] == 0)
        dp[i++][0] = 1;
    while (i < n)
        dp[i++][0] = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (table[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}

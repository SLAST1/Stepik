#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> f(n, vector<int> (m));
 
    for (auto& i : f)
        for (int& j : i)
            cin >> j; 

    vector<vector<int>> dp(n, vector<int> (m));

    dp[0][0] = 0;
    for (int i = 1; i < m; ++i)
        dp[0][i] = abs(f[0][i] - f[0][i - 1]) + dp[0][i - 1];
    for (int i = 1; i < n; ++i)
        dp[i][0] = abs(f[i][0] - f[i - 1][0]) + dp[i - 1][0];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = min(abs(f[i][j] - f[i - 1][j]) + dp[i - 1][j],
                    abs(f[i][j] - f[i][j - 1]) + dp[i][j - 1]);
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}

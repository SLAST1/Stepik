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

long long inf = 1e16;

int index_of_diag(int i, int j, int n, int m)
{
    return n + m - 2 - i - (m - j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // input;
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (auto& i : a)
        for (auto& j : i)
            cin >> j;

    // dp
    vector<vector<long long>> dp(n, vector<long long>(m));
    vector<long long> minm(m);
    vector<long long> minn(n);
    vector<long long> mind(m + n - 1);
    for (int i = 0; i < m; ++i)
        minm[i] = inf;
    for (int i = 0; i < n; ++i)
        minn[i] = inf;
    for (int i = 0; i < m + n - 1; ++i)
        mind[i] = inf;
    dp[0][0] = a[0][0];
    minn[0] = a[0][0];
    minm[0] = a[0][0];
    mind[n - 1] = a[0][0];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            int ind = index_of_diag(i, j, n, m);
            dp[i][j] = min(min(minn[i], minm[j]), mind[ind]) + a[i][j];
            minn[i] = min(minn[i], dp[i][j]);
            minm[j] = min(minm[j], dp[i][j]);
            mind[ind] = min(mind[ind], dp[i][j]);
        }
    }

    // recovery
    vector<pair<int, int>> coords;
    int i = n - 1, j = m - 1;
    while (true)
    {
        coords.push_back(make_pair(i, j));
        if (i == 0 && j == 0)
            break;
        long long diff = dp[i][j] - a[i][j];
        int temp = i;
        --i;
        while (i >= 0 && diff != dp[i][j])
            --i;
        if (i >= 0)
            continue;
        i = temp;
        temp = j;
        --j;
        while (j >= 0 && diff != dp[i][j])
            --j;
        if (j >= 0)
            continue;
        j = temp;
        --i; --j;
        while (j >= 0 && i >= 0 && diff != dp[i][j])
        {
            --i;
            --j;
        }
    }

    // print
    cout << dp[n - 1][m - 1] << " " << coords.size() << nl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i].first + 1 << " " << coords[i].second + 1 << nl;

    return 0;
}

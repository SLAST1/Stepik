#include <bits/stdc++.h>

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
    
    int n;
    cin >> n;
    vector<vector<bool>> graph(n, vector<bool> (n, false));
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        int x;
        for (int j = 0; j < t; ++j)
        {
            cin >> x;
            graph[i][x - 1] = true;
        }
    }

    for (vector<bool>& i : graph)
    {
        for (bool j : i)
            cout << j;
        cout << nl;
    }
    return 0;
}

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
   
    vvi graph(n, vi(n)); 

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char x;
            cin >> x;
            graph[i][j] = x - '0';
        }
    }

    int x = 0;
    vector<pair<int, int>> graph1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = x; j < n; ++j)
            if (graph[i][j] == 1)
                graph1.push_back(make_pair(i + 1, j + 1));
        ++x;
    }

    cout << graph1.size() << nl;
    for (auto& i : graph1)
        cout << i.first << " " << i.second << nl;
    return 0;
}

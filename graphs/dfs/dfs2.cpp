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

vi used;
vvl graph;
vi answer;
int countt = 1;

void dfs(int x)
{
    used[x] = true;
    answer[x] = countt;
    for (auto& u : graph[x])
    {
        if (used[u])
            continue;
        dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    used.resize(n + 1, false);
    graph.resize(n + 1);
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    answer.resize(n + 1, 0); 
    for (int i = 1; i <= n; ++i)
    {
        if (answer[i])
            continue;
        dfs(i);
        ++countt;
    }

    cout << countt - 1 << nl;
    for (int i = 1; i <= n; ++i)
        cout << answer[i] << " ";
    cout << nl;

    return 0;
}

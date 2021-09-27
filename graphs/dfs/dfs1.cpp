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

vector<list<int>> graph;
vector<bool> used;
vector<int> answer;


void dfs(int x)
{
    used[x] = true;
    answer.push_back(x);
    for (auto& u : graph[x])
    {
        if (used[u])
            continue;
        dfs(u);
        answer.push_back(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;    
   
    graph.resize(n + 1); 
    used.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int x;
    cin >> x;
    dfs(x);

    cout << answer.size() << nl;
    for (auto& i : answer)
        cout << i << " ";
    cout << nl;
    return 0;
}

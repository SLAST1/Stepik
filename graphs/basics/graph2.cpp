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
    
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a-1].insert(b); 
        v[b-1].insert(a);
    }
    for(set<int> i : v)
    {
        cout << i.size() << ' ';
        for(int j : i)
            cout << j << ' ';
        cout << nl;
    }
    return 0;
}

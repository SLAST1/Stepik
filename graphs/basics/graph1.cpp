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

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        cout << count(begin(s), end(s), '1') << " ";
        for (int j = 0; j < s.size(); ++j)
        {
           if (s[j] == '1')
              cout << j + 1 << " "; 
        }
        cout << nl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>

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
    int w, n;
    cin >> w >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
    }
    
    if (sum >= w)
        cout << w << nl;
    else
        cout << sum << nl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <utility>

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

int inf = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s, n;
    cin >> s >> n;
    vector<pair<int, double>> w(n);
    for (auto& i : w)
        cin >> i.first;
    for (auto& i : w)
        cin >> i.second;

    double sum = 0;
    for (auto& i : w)
    {
        if (i.first == 0)
        {
            sum += i.second;
            i.second = -1;
        }
        else
            i.second = i.second / i.first;
    }

    sort(begin(w), end(w),[](pair<int, double> a, pair<int, double> b) {
        return a.second > b.second;
    });

    for (auto& i : w)
    {
        if (i.first >= s)
        {
            sum += s * i.second;
            break;
        }
        else 
        {
            s -= i.first;
            sum += i.first * i.second;
        }
    }
    int res = (int) sum;
    cout << res + (sum - res > 0) << nl;
    return 0;
}

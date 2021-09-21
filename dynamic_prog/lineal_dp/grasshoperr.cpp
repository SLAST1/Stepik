#include <iostream>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

long long norm(long long d, long long MOD)             
{
    return ((d % MOD) + MOD) % MOD;  
}

long long Madd(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) + norm(y, MOD), MOD);
}

long long Msub(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) - norm(y, MOD), MOD);
}

long long Mmul(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) * norm(y, MOD), MOD);
}

void solve()
{
    int n, k;

    cin >> n >> k;
    int mod = 1e9 + 7;
    char a[n];
    forn (i, n)
        cin >> a[i];
    
    vector<int> pr(3); 
    pr[0] = 0;
    pr[1] = 1;
    pr[2] = 1 + (a[0] == '0' ? 1 : 0);
    for (int i = 2; i < n + 1; ++i)
    {
        if (a[i - 1] == '1')
            pr.push_back(pr[pr.size() - 1]);
        else
        {
            int temp;
            if (i >= k)
                temp = Msub(pr[i], pr[i - k], mod);
            else
                temp = Msub(pr[i], pr[0], mod);
            pr.push_back(Madd(temp, pr[pr.size() - 1], mod));
        }
    }
    cout << Msub(pr[pr.size() - 1], pr[pr.size() - 2], mod) << endl;
}

int main()      
{
    int t = 1;
    forn(tt, t)
        solve();
    return 0;
}

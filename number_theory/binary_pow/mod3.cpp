#include <iostream>
#include <vector>

using namespace std;

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

long long my_pow(long long x, long long n, long long mod)
{
    long long res = 1;
    long long number = x;
    while (n > 0) {
        if (n % 2 == 1) {
            res = Mmul(res, number, mod);
        }
        number = Mmul(number, number, mod);
        n /= 2;
    }
    return res;
}

long long Mdiv(long long x, long long y, long long MOD)
{
    return Mmul(x, my_pow(y, MOD - 2LL, MOD), MOD);
}

long long extgcdd(long long r1, long long r2, long long& x1,
        long long& y1, long long& x2, long long& y2, bool first = true)
{
    if (r1 < r2) return extgcdd(r2, r1, y1, x1, y2, x2, first);
    if (first)
    {
        x1 = 1; y1 = 0; x2 = 0; y2 = 1;
    }
    if (r2 == 0) return r1;
    int x = x1 - (r1 / r2) * x2;
    int y = y1 - (r1 / r2) * y2;
    x1 = x2; x2 = x; y1 = y2; y2 = y;
    return extgcdd(r2, r1 % r2, x1, y1, x2, y2, false);
}

long long Mdiv2(long long a, long long b, long long MOD)
{
    long long x1, x2, y1, y2;
    long long d = extgcdd(b, MOD, x1, y1, x2, y2);
    if (a % d != 0)
        return -1LL;
    return Mmul((a / d), x1, MOD);
}

vector<int> factorial(long long n, long long MOD)
{
    vector<int> res;
    int result = 1;
    int m = 1;
    res.push_back(1);
    while (m != n + 1)
    {
        result = Mmul(result, m, MOD);
        res.push_back(result);
        ++m;
    }
    return res;
}

long long Cn_mk(long long n, long long mk, long long mod, vector<int>& factorials)
{
    long long first = factorials[n];
    long long second = Mmul(factorials[Msub(n, mk, mod)], factorials[mk], mod);
    return Mdiv2(first, second, mod);
}

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    int mod = 1e9 + 7;
    int result = 0;
    vector<int> factorials;
    factorials = factorial(n, mod);
    
    for (int k = 1; k <= l; ++k)
    {
        long long mk = Mmul(m, k, mod);
        long long c;
        if (n < mk)
            c = 0;
        else
            c = Cn_mk(n, mk, mod, factorials);
        result = Madd(result, c, mod);
    }
    cout << result << endl;
    return 0;
}

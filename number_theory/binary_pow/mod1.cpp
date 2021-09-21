#include <iostream>

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

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d; 
    int mod = 1e9 + 7;
    cout << Mdiv(Madd(Mmul(a, d, mod), Mmul(b, c, mod), mod), 
            Mmul(b, d, mod), mod) << endl;
    return 0;
}

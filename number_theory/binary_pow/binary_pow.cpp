#include <iostream>

using namespace std;

long long norm(long long d, long long MOD)
{
    return ((d % MOD) + MOD) % MOD;
}

long long Mmul(long long x, long long y, long long MOD)
{
    return norm(norm(x, MOD) * norm(y, MOD), MOD);
}

int my_pow(int n, int mod)
{
    int res = 1;
    int number = n;
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            res = Mmul(res, number, mod);
        }
        number = Mmul(number, number, mod);
        n /= 2;
    }
    return res;
}

int main()
{
    int n, mod;
    cin >> n >> mod;
    cout << my_pow(n, mod) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const long double EPS = 1e-9;

vector<double> v;

long double func(double x)
{
    long double result = 0;
    for (int i = 0; i < v.size(); ++i)
        result += v[i] * pow(x, v.size() - i - 1);
    return result;
}

long double find_root()
{
    long double l = -1e9;
    long double r = 1e9;
    
    while (r - l > EPS)
    {
        long double mid = (l + r) / 2;
        if (func(mid) < 0) 
            l = mid;
        else
            r = mid;
    }
    return (l + r) / 2;
}

int main()
{
    int n;
    cout << fixed;
    cout.precision(16);
    cin >> n;
    v.resize(n + 1);
    for (auto& i : v)
        cin >> i;
    cout << find_root() << endl;
    return 0;
}

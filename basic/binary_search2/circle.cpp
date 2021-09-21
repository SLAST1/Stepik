#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const long double EPS = 1e-12;

vector<double> v;
double rad;
double cx, cy;
double x;

long double func(double x)
{
    long double result = 0;
    for (int i = 0; i < v.size(); ++i)
        result += v[i] * pow(x, v.size() - i - 1);
    return result;
}

double distance(double x, double y)
{
    return sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
}

long double find_point()
{
    long double l = -1e9;
    long double r = x;
    
    while (r - l > EPS)
    {
        long double mid = (l + r) / 2;
        if (distance(mid, func(mid)) > rad)
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
    cin >> cx >> cy >> rad;
    cin >> n;
    v.resize(n + 1);
    for (auto& i : v)
        cin >> i;
    cin >> x;
    cout << find_point() << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int mod = 1791791791;
int a, b;

int NextRand(long long& cur)
{
    cur = (cur * a + b) % mod;
    return cur;
}

int main()
{
    int n;
    cin >> n;
    long long cur;
    cin >> cur >> a >> b;
    vector<int> v(n);
    for (int& i : v)
        i = NextRand(cur);
    int first_max = v[0];
    int first_ind = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > first_max)
        {
            first_max = v[i];
            first_ind = i;
        }
    }
    int second_max = INT_MIN;
    int second_ind = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > second_max && first_ind != i)
        {
            second_max = v[i];
            second_ind = i;
        }
    }
    cout << first_ind + 1 << " " << second_ind + 1 << endl;
    return 0;
}

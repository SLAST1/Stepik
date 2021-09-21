#include <iostream>
#include <vector>

#define nl '\n'

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    bool positive = false;
    long long mx = -1e10;
    for (int& i : v)
    {
        cin >> i;
        if (i >= 0)
            positive = true;
        if (mx < i)
            mx = i;
    }
    vector<long long> sums(n + 1);
    sums[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        long long x  = sums[i - 1] + v[i - 1];
        if (x < 0)
           sums[i] = 0;
        else 
           sums[i] = x; 
        if (mx < sums[i] && positive)
            mx = sums[i];
    }
    cout << mx << nl;
    return 0;
}

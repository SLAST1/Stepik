#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool check(int mid, int k)
{
    int count = 0;
    for (int& i : v)
        count += i / mid;
    return count >= k;
}

int solve(int k, int max)
{
    int l = 0, r = max + 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (check(m, k))
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    int n, k;
    cin >> n >> k;
    v.resize(n); 
    int max = 0;
    for (int& i : v)
    {
        cin >> i;
        if (i > max)
           max = i; 
    }
    cout << solve(k, max) << endl;
    return 0;
}

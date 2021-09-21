#include <iostream>
#include <vector>

using namespace std;
vector<int> coords;

bool check(int mid, int k)
{
    int count = 1;
    int last = coords[0];
    for (int c : coords)
    {
        if (c - last >= mid)
        {
            ++count;
            last = c;
        }
    }
    return count >= k;
}

int solve(int n, int k)
{
    int l = 0;
    int r = coords[n - 1] - coords[0] + 1;
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
    coords.resize(n);
    for (int& i : coords)
        cin >> i;
    cout << solve(n, k) << endl;
    return 0; 
}

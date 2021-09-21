#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        int l = -1, r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (v[m] > x)
                l = m;
            else
                r = m;
        }
        if (r == n)
            cout << "NO SOLUTION" << endl;
        else 
            cout << r + 1 << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int l = -1, r = n;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
            l = (l + r) / 2;
        else if (x == 1)
            r = (l + r) / 2;
    }
    cout << r << endl;
    return 0;
}

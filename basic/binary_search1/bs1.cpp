#include <iostream>

using namespace std;


int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < t; ++i)
    {
        int k;
        cin >> k;
        int l = -1, r = n;
        int count = 0;
        while (l + 1 < r)
        {
            ++count;
            int mid = (l + r) / 2;
            if (mid < k)
               l = mid;
            else
               r = mid; 
        }
        cout << count << endl;
    }
    return 0;
}

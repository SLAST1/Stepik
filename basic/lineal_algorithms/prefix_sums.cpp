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
    vector<long long> sums(n + 1);
    sums[0] = 0;
    for (int i = 1; i < n + 1; ++i)
        sums[i] = sums[i - 1] + v[i - 1];
    cout << endl;
    for (int i = 0; i < t; ++i)
    {
        int a, b;
        cin >> a >> b; 
        cout << sums[b] - sums[a - 1] << endl;
    }
    return 0;
}

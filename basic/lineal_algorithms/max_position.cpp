#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    int i = 0;
    int max = v[0];
    for (int j = 0; j < n; ++j)
    {
        if (v[j] > max)
        {
            max = v[j];
            i = j;
        }
    }
    cout << i + 1 << endl;
    return 0;
}

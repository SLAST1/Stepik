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
    long long sum = 0;
    for (int& i : v)
        sum += i;
    cout << sum << endl;
    return 0;
}

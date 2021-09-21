#include <iostream>
#include <vector>

using namespace std;

void sieve(int n)
{
    vector<bool> s(n + 1, true);
    int count = 0;
    s[0] = false;
    s[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (s[i])
            for (int j = i * i; j <= n; j += i)
            {
                if (s[j] == true)
                    count += i;
                s[j] = false;
            }
    }
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    return 0;
}

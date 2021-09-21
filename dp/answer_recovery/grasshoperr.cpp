#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;

class sliding_window {
public:

    ll get_min() {
        return d.front();
    }

    void push_back(ll x) {
        while (!d.empty() && d.back() > x)
            d.pop_back();
        d.push_back(x);
    }

    void pop_front(ll x) {
        if (!d.empty() && d.front() == x)
            d.pop_front();
    }

private:
    deque<ll> d;
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& i : a)
        cin >> i;

    vector<ll> dp(n + 1);
    sliding_window s;
    dp[0] = 0;
    s.push_back(0);
   
    for (int i = 1; i < n + 1; ++i)
    {
        dp[i] = s.get_min() + a[i - 1];
        s.push_back(dp[i]);
        if (i - k >= 0)
            s.pop_front(dp[i - k]);
    }
    vector<int> coords;
    int i = n;
    while (i >= 1)
    {
        coords.push_back(i);
        ll diff = dp[i] - a[i - 1];
        --i;
        while (diff != dp[i])
            --i;
    }
    cout << dp[n] << " " << coords.size() << endl;
    for (int i = coords.size() - 1; i >= 0; --i)
        cout << coords[i] << " ";
    cout << endl;
    return 0;
}

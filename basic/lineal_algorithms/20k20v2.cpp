#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n + 1; i < 1e8; ++i)
    {
        string s = to_string(i);
        if (s.find('0') != -1 || s.find('2') != -1)
            continue;
        set<char> chars;
        for (int j = 0; j < s.size(); ++j)
            chars.insert(s[j]);
        if (s.size() == chars.size()) {
            cout << s << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

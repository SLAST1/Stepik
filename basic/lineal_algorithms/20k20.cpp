#include <iostream>
#include <string>
#include <set>

using namespace std;
string generator(int n)
{
    string res;
    char c = '0';
    for (int i = 0; i < n + 1; ++i)
    {
        if (c == '1')
            c += 2;
        else
            ++c;
         res += c;
    }
    return res;
}

string generator1(string& s)
{
    int pos = s.find('9');
    set<char> st;
    
    for (int i = 0; i < pos - 1; ++i)
        st.insert(s[i]);
    char c = s[pos - 1] + 1;
    while (c == '2' || (st.find(c) != st.end()))
        ++c;
    s[pos - 1] = c;
    st.insert(c);

    for (int i = pos; i < s.size(); ++i)
    {
        c = '1';
        while (c == '2' || (st.find(c) != st.end()))
            ++c;
        s[i] = c;
        st.insert(c);
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    ++n;
    string s = to_string(n);
    if (s.size() > 8)
    {
        cout << -1 << endl;
        return 0;
    }
    set<char> st;
    bool change = false;
    bool first = false;
    for (int i = 0; i < s.size(); ++i)
    {
        if (first)
            s[i] = '1';
        while (true)
        {
            if (s[i] == '9' && st.find('9') != st.end())
            {
                change = true;
                break;
            }
            if (s[i] == '0' || s[i] == '2' || (st.find(s[i]) != st.end()))
            {
                ++s[i];
                first = true;
            }
            else
                break;
        }
        st.insert(s[i]);
    }
    if (change)
        if (s.find('9') == 0)
        {
            if (s.size() + 1 > 8 && change)
                cout << -1 << endl;
            else
                cout << generator(s.size()) << endl;
        }
        else
            cout << generator1(s) << endl;
    else
        cout << s << endl;
}

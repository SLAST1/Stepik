#include <iostream>

using namespace std;


int main()
{
    int a, b;
    cin >> a >> b;
    int count = 0;
    while (b %= a)
    {
        swap(a, b);
        ++count;
    }

    cout << count << endl;
    return 0;
}

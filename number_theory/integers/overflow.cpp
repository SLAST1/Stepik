#include <iostream>

using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    
    cout << (a * b * c) / (a * b + b * c + a * c) << endl;
    return 0;
}

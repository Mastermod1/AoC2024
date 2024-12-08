#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::vector<int> a;
    std::vector<int> b;
    a.reserve(1000);
    b.reserve(1000);
    for (int i = 0; i < 1000; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum += abs(a[i] - b[i]);
    }
    cout << sum << endl;
}

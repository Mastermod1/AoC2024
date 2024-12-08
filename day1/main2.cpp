#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::vector<int> a;
    std::unordered_map<int, int> b;
    a.reserve(1000);
    for (int i = 0; i < 1000; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b[y]++;
    }

    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        sum += a[i] * b[a[i]];
    }
    cout << sum << endl;
}

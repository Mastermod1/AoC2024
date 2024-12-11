#include <bits/stdc++.h>

using namespace std;

struct pair_hash{
    inline size_t operator()(const pair<uint64_t, int>& p) const
    {
        return p.first * 31 + p.second;
    }
};


unordered_map<pair<uint64_t, int>, uint64_t, pair_hash> m;

uint64_t dp(uint64_t stone, int calls)
{
    auto p = make_pair(stone, calls);
    if (m.find(p) != m.end())
        return m[p];
    if (calls == 0)
        return 1;

    uint64_t res = 0;
    if (stone == 0)
    {
        res = dp(1, calls - 1);
    }
    else if (auto str = to_string(stone); str.length() % 2 == 0)
    {
        unsigned long long len = str.length();
        unsigned long long half = len / 2;
        string first = str.substr(0, half);
        string second = str.substr(half);
        res = dp(stoull(first), calls - 1) + dp(stoull(second), calls - 1);
    }
    else
    {
        res = dp(stone * 2024, calls - 1);
    }
    m[p] = res;
    return res;
}

int main(){
    string line = "";
    getline(cin, line);
    list<int> stones;
    string num = "";
    for(int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ' || line[i] == '\n')
        {
            stones.push_back(stoi(num));
            num = "";
            continue;
        }
        num += line[i];
    }
    stones.push_back(stoi(num));

    uint64_t res = 0;
    for (auto x : stones)
    {
        res += dp(x, 75);
    }
    cout << res << endl;
}

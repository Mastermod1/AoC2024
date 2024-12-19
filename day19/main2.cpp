#include <bits/stdc++.h>

using namespace std;

bool startsWith(const string& s, const string& with)
{
    for (long long i = 0; i < with.length(); i++)
    {
        if (with[i] != s[i])
        {
            return false;
        }
    }
    return true;
}

unordered_map<string, long long> dp;
long long rec(const string& str, const unordered_set<string>& avail)
{
    if (dp.find(str) != dp.end())
        return dp[str];

    if (str == "")
        return 1;

    long long count = 0;
    for (auto p : avail)
    {
        if (startsWith(str, p))
        {
            count += rec(str.substr(p.length()), avail);
        }
    }
    dp[str] = count;
    return count;
}

int main()
{
    string line;
    getline(cin, line);
    line += ',';
    auto last_pos = 0;
    auto pos = line.find(',');
    unordered_set<string> avail;
    long long max_len = 0;
    while (pos != string::npos)
    {
        auto sample = line.substr(last_pos, pos - last_pos);
        avail.insert(sample);
        max_len = max((long long)sample.length(), max_len);
        last_pos = pos + 2;
        pos = line.find(',', pos + 1);
    }
    long long res = 0;
    while(getline(cin, line))
    {
        if (line == "")
            continue;
        res += rec(line, avail);
    }
    cout << res << endl;
}

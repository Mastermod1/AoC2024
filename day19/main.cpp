#include <bits/stdc++.h>

using namespace std;

bool rec(const string& str, const unordered_set<string>& avail, int max_len, int start = 0)
{
    if (start == str.length())
        return  true;
    for (int i = 1; i <= min(max_len, (int)str.length() - start); i++)
    {
        string s = str.substr(start, i);
        if (avail.find(s) == avail.end())
            continue;
        if (rec(str, avail, max_len, start + s.length()))
            return true;
    }
    return false;
}

int main()
{
    string line;
    getline(cin, line);
    line += ',';
    auto last_pos = 0;
    auto pos = line.find(',');
    unordered_set<string> avail;
    int max_len = 0;
    while (pos != string::npos)
    {
        auto sample = line.substr(last_pos, pos - last_pos);
        avail.insert(sample);
        max_len = max((int)sample.length(), max_len);
        last_pos = pos + 2;
        pos = line.find(',', pos + 1);
    }
    int res = 0;
    while(getline(cin, line))
    {
        if (line == "")
            continue;
        if (rec(line, avail, max_len))
            res++;
    }
    cout << res << endl;
}

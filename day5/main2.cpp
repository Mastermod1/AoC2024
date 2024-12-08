#include <bits/stdc++.h>

using namespace std;


int main() {
    int sum = 0;
    string line = "";
    map<int, vector<int>> m;
    while(getline(cin, line) and line != "")
    {

        int start = 0;
        int num1 = 0;
        while (start < line.length() and line[start] != '|')
        {
            num1 = 10 * num1 + (line[start] - '0');
            start++;
        }
        start++;
        int num2 = 0;
        while (start < line.length() and line[start] != '|')
        {
            num2 = 10 * num2 + (line[start] - '0');
            start++;
        }
        m[num1].push_back(num2);
    }
    while(getline(cin, line))
    {
        vector<int> o;
        int start = 0;
        int num1 = 0;
        while (start < line.length())
        {
            if (line[start] == ',')
            {
                o.push_back(num1);
                start++;
                num1 = 0;
                continue;
            }
            num1 = 10 * num1 + (line[start] - '0');
            start++;
        }
        o.push_back(num1);
        unordered_set<int> present;
        int middle = o.size() / 2;
        bool success = true;
        for (int i = 0; i < o.size() and success; i++)
        {
            auto before = m[o[i]];
            present.insert(o[i]);
            for (auto test : before)
            {
                if (present.find(test) != present.end())
                {
                    success = false;
                    break;
                }
            }
        }
        if (not success)
        {
            unordered_set<int> s(o.begin(), o.end());
            unordered_map<int, unordered_set<int>> mm;
            for (auto x : m)
            {
                if (s.find(x.first) == s.end())
                    continue;
                mm[x.first];
                for (auto y : x.second)
                {
                    if (s.find(y) == s.end())
                        continue;
                    mm[y].insert(x.first);
                }
            }
            int mid_val = 0;
            for (int i = 0; i <= middle; i++)
            {
                for (auto [num, others] : mm)
                {
                    if (others.empty())
                    {
                        mid_val = num;
                        for (auto& [_, arr] : mm)
                        {
                            arr.erase(num);
                        }
                        mm.erase(num);
                        break;
                    }
                }
            }
            sum += mid_val;
        }
    }
    cout << sum << endl;
}

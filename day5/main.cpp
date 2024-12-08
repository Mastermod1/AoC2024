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
        if (success)
            sum += o[middle];
    }
    cout << sum << endl;

    
    
}

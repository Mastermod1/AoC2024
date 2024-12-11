#include <bits/stdc++.h>

using namespace std;

int main(){
    string line = "";
    getline(cin, line);
    list<string> stones;
    string num = "";
    for(int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ' || line[i] == '\n')
        {
            stones.push_back(num);
            num = "";
            continue;
        }
        num += line[i];
    }
    stones.push_back(num);

    int t = 25;
    while(t--)
    {
        for (auto it = stones.begin(); it != stones.end(); it++)
        {
            if (*it == "0")
            {
                *it = "1";
            }
            else if (it->length() % 2 == 0)
            {
                unsigned long long len = it->length();
                unsigned long long half = len / 2;
                string first = it->substr(0, half);
                string second = it->substr(half, half);
                unsigned long long k = 0;
                while (k < second.length() and second[k] == '0') k++;
                second = k == second.length() ? "0" : second.substr(k);
                stones.insert(it, first);
                *it = second;
            }
            else
            {
                *it = to_string(stoull(*it) * 2024);
            }
        }
        // for (auto x : stones)
        //     cout << x << " ";
        // cout << endl;
    }
    cout << stones.size() << endl;
}

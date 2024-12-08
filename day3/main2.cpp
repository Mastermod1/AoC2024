#include <bits/stdc++.h>

using namespace std;

pair<int, int> find_modifier(std::string& line, int pos)
{
    int disabled = line.find("don't()", pos);
    int enabled = line.find("do()", pos);
    return {enabled, disabled};
}

//  0                  10      12       15         18         22       30
// xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))

int main() {
    int sum = 0;
    string line = "";
    string all_input = "";
    while(getline(cin, line))
    {
        all_input += line;
    }

    line = all_input;
    int pos = 0;
    auto modifier = find_modifier(line, pos);
    while (pos < line.length())
    {
        int start_pos = line.find("mul(", pos);
        if (start_pos == std::string::npos)
            break;
        if (modifier.second != string::npos and start_pos > modifier.second)
        {
            modifier = find_modifier(line, modifier.second + 1);
            pos = modifier.first;
            continue;
        }
        start_pos += 4;
        
        string n1 = "";
        int end = start_pos + 3;
        while (isdigit(line[start_pos]) and start_pos < end)
        {
            n1 += line[start_pos];
            start_pos++;
        }
        if (line[start_pos] == ',')
            start_pos++;
        else
        {
            pos = start_pos;
            continue;
        }

        string n2 = "";
        end = start_pos + 3;
        while (isdigit(line[start_pos]) and start_pos < end)
        {
            n2 += line[start_pos];
            start_pos++;
        }
        if (line[start_pos] == ')')
        {
            // multilpy and sum
            sum += stoi(n1) * stoi(n2);
            start_pos++;
            pos = start_pos;
            continue;
        }
        else
        {
            pos = start_pos;
            continue;
        }
    }

    cout << sum << endl;
}

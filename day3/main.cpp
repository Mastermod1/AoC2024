#include <bits/stdc++.h>

using namespace std;

bool in_range(int val)
{
    return val >= 1 and val <= 3;
}

int main() {
    int sum = 0;
    string line = "";
    while(getline(cin, line))
    {
        int pos = 0;
        while (pos < line.length())
        {
            int start_pos = line.find("mul(", pos);
            if (start_pos == std::string::npos)
                break;
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
            return 5;
        }
    }
    cout << sum << endl;
}

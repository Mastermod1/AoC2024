#include <bits/stdc++.h>

using namespace std;

int main()
{
    int reg[7] = {0, 1, 2, 3, 0, 0 ,0};
    string line;
    for (int i = 4; i < 7; i++)
    {
        getline(cin, line);
        stringstream ss(line);
        ss.ignore(12);
        ss >> reg[i];
    }
    getline(cin, line);
    getline(cin, line);
    string output = "";
    for (int i = 9; i < line.length();)
    {
        int code = line[i] - '0';
        int oper = line[i+2] - '0';
        switch (code)
        {
            case 0:
            {
                int div = reg[4] / pow(2, reg[oper]);
                reg[4] = div;
                i += 4;
                break;
            }
            case 1:
            {
                reg[5] ^= oper;
                i += 4;
                break;
            }
            case 2:
            {
                reg[5] = reg[oper]%8;
                i += 4;
                break;
            }
            case 3:
            {
                if (reg[4] == 0)
                {
                    i += 4;
                    break;
                }
                i = 9 + oper;
                break;
            }
            case 4:
            {
                reg[5] ^= reg[6];
                i += 4;
                break;
            }
            case 5:
            {
                output += (reg[oper]%8) + '0';
                output +=  + ",";
                i += 4;
                break;
            }
            case 6:
            {
                int div = reg[4] / pow(2, reg[oper]);
                reg[5] = div;
                i += 4;
                break;
            }
            case 7:
            {
                int div = reg[4] / pow(2, reg[oper]);
                reg[6] = div;
                i += 4;
                break;
            }
        }
    }
    cout << output.substr(0, output.length() - 1) << endl;
}

#include <bits/stdc++.h>

using namespace std;

string w1 = "MAS";
string w2 = "SAM";

int main() {
    int sum = 0;
    string line = "";
    vector<string> all_input;
    while(getline(cin, line))
    {
        all_input.push_back(line);
    }

    int count = 0;
    for (int i = 0; i < all_input.size(); i++)
    {
        for (int j = 0; j < all_input[i].length(); j++)
        {
            if (all_input[i][j] == 'A')
            {
                if (i - 1 < 0 or j - 1 < 0 or i + 1 >= all_input.size() or j + 1 >= all_input[i].size())
                    continue;
                string t1 = "", t2 = "";
                t1 += all_input[i - 1][j - 1];
                t1 += all_input[i][j];
                t1 += all_input[i + 1][j + 1];
                t2 += all_input[i - 1][j + 1];
                t2 += all_input[i][j];
                t2 += all_input[i + 1][j - 1];
                if ((t1 == w1 or t1 == w2) and (t2 == w1 or t2 == w2))
                    count++;
            }
        }
    }
    cout << count << endl;
}

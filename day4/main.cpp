#include <bits/stdc++.h>

using namespace std;

string w1 = "XMAS";
string w2 = "SAMX";

int dfs(vector<string>& s, int row, int col, pair<int, int> dir, int n, int m, string letters = "")
{
    if (letters == w1 or letters == w2)
        return 1;
    if (row < 0 or row >= n or col < 0  or col >= m or letters.length() >= 4)
        return 0;

    letters += s[row][col];
   
    return dfs(s, row + dir.first, col + dir.second, dir, n, m, letters);
}

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
            count += dfs(all_input, i, j, {1, 0}, all_input.size(), all_input[i].length());
            count += dfs(all_input, i, j, {0, 1}, all_input.size(), all_input[i].length());
            count += dfs(all_input, i, j, {1, 1}, all_input.size(), all_input[i].length());
            count += dfs(all_input, i, j, {1, -1}, all_input.size(), all_input[i].length());
        }
    }
    cout << count << endl;
}

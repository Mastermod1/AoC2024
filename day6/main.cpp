#include <bits/stdc++.h>

using namespace std;


int main() {
    string line = "";
    vector<string> v;
    while(getline(cin, line))
    {
        v.push_back(line);
    }

    int H = v.size();
    int W = v[0].size();
    auto find = [&](){
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (v[i][j] == '^')
                    return make_pair(i, j);
        return make_pair(-1, -1);
    };

    auto pos = find();
    cout << pos.first << " " << pos.second << endl;
    int sum = 0;
    vector<pair<int, int>> dirs = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int dir_index = 0;

    while (pos.first >= 0 and pos.second >= 0 and pos.first < H and pos.second < W)
    {
        // cout << pos.first << " " << pos.second << " " << v[pos.first][pos.second] << endl;
        if (v[pos.first][pos.second] == '.')
        {
            sum++;
            v[pos.first][pos.second] = 'X';
        }
        if (v[pos.first][pos.second] == '#')
        {
            pos.first += dirs[dir_index].first;
            pos.second -= dirs[dir_index].second;
            dir_index = (dir_index + 1)%4;
            continue;
        }
        pos.first -= dirs[dir_index].first;
        pos.second += dirs[dir_index].second;
    }
    cout << sum + 1 << endl;
}

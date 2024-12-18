#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int main()
{
    vector<pair<int, int>> corrupted; 
    string line;
    while(getline(cin, line))
    {
        stringstream ss(line);
        int x, y;
        ss >> x;
        ss.ignore(1);
        ss >> y;
        corrupted.emplace_back(y, x);
    }
    const int h = 71;
    const int w = 71;
    const int bytes = 1024;
    // const int h = 7;
    // const int w = 7;
    // const int bytes = 12;
    vector<vector<char>> map(h, vector<char>(w, '.'));
    vector<vector<int>> vals(h, vector<int>(w, INT_MAX));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    for (int i = 0; i < bytes; i++)
        map[corrupted[i].first][corrupted[i].second] = '#';
    pair<int, int> st = {0, 0};
    vals[0][0] = 0;
    int nodeCount = h * w - bytes;
    vector<pair<int, int>> dirs{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    while(nodeCount--)
    {
        int min = INT_MAX;
        pair<int, int> pos;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (vals[i][j] < min and not vis[i][j])
                {
                    min = vals[i][j];
                    pos = {i, j};
                }
            }
        }
        vis[pos.first][pos.second] = true;
        for (auto dir : dirs)
        {
            auto np = make_pair(pos.first + dir.first, pos.second + dir.second);
            if (np.first < 0 or np.second < 0 or np.first >= h or np.second >= w or map[np.first][np.second] == '#' or vis[np.first][np.second])
                continue;
            int val = vals[pos.first][pos.second] + 1;
            if (val < vals[np.first][np.second])
            {
                vals[np.first][np.second] = val;
            }
        }
    }
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }
    cout << vals[h - 1][w - 1] << endl;
}

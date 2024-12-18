#include <bits/stdc++.h>
#include <climits>
#include <sstream>

using namespace std;

int dijkstra(const vector<vector<char>>& map, int h, int w, int bytes)
{
    vector<vector<int>> vals(h, vector<int>(w, INT_MAX));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
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
                if (vals[i][j] != INT_MAX and vals[i][j] < min and not vis[i][j])
                {
                    min = vals[i][j];
                    pos = {i, j};
                }
            }
        }

        if (min == INT_MAX)
            return vals[h-1][w-1];

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
    return vals[h - 1][w - 1];
}

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
    // const int h = 7;
    // const int w = 7;
    int bytes = corrupted.size();
    vector<vector<char>> map(h, vector<char>(w, '.'));
    pair<int, int> pos{-1, -1};
    for (auto corr : corrupted)
        map[corr.first][corr.second] = '#';
    for (int i = corrupted.size() - 1; i >= 0; i--)
    {
        auto corr = corrupted[i];
        map[corr.first][corr.second] = '.';
        bytes--;
        auto val = dijkstra(map, h, w, bytes);
        // cout << "Map\n";
        // for (auto i = 0; i < h; i++)
        // {
        //     for (auto j = 0; j < w; j++)
        //         cout << map[i][j] << " ";
        //     cout << endl;
        // }
            
        pos = corr;
        if (val != INT_MAX)
        {
            break;
        }
    }
    
    cout << pos.second << "," << pos.first << endl;
}

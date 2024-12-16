#include <bits/stdc++.h>
#include <climits>

using namespace std;

enum class dir
{
    E = 0,
    S,
    W,
    N
};

map<pair<int, int>, dir> map_rot {
    {{1,0}, dir::S},
    {{-1,0}, dir::N},
    {{0,1}, dir::E},
    {{0,-1}, dir::W},
};

int min_rot(dir start, dir end)
{
    int clockwise = (static_cast<int>(end) - static_cast<int>(start) + 4)%4;
    int counter = (static_cast<int>(start) - static_cast<int>(end) + 4)%4;
    return min(clockwise, counter);
}

struct node {
    int val;
    int y, x;
};


int main()
{
    vector<string> map;
    string line;
    while(getline(cin, line))
    {
        map.push_back(line);
    }
    int score = INT_MAX;
    vector<vector<int>> vals(map.size(), vector<int>(map.front().length(), INT_MAX));
    vector<vector<bool>> vis(map.size(), vector<bool>(map.front().length(), false));
    vector<vector<dir>> rotation(map.size(), vector<dir>(map.front().length(), dir::E));
    list<pair<int, int>> nodes;
    pair<int, int> res;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map.front().length(); j++)
        {
            if (map[i][j] == 'S')
            {
                vals[i][j] = 0;
                nodes.emplace_back(i, j);
            }
            else if (map[i][j] != '#')
            {
                if (map[i][j] == 'E')
                    res = {i, j};
                nodes.emplace_back(i, j);
            }
        }
    }

    auto size = nodes.size();
    vector<pair<int, int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i = 0; i < size; i++)
    {
        int val = INT_MAX;
        pair<int, int> node;
        for (auto x : nodes)
        {
            if (vis[x.first][x.second] == false and val > vals[x.first][x.second])
            {
                val = vals[x.first][x.second];
                node = x;
            }
        }
        vis[node.first][node.second] = true;

        for (auto dir : dirs)
        {
            auto np = make_pair(node.first + dir.first, node.second + dir.second);
            if (np.first < 0 or np.second < 0 or np.first >= map.size() or np.second >= map.front().length() or map[np.first][np.second] == '#' or vis[np.first][np.second])
                continue;
            rotation[np.first][np.second] = map_rot[dir];
            vals[np.first][np.second] = vals[node.first][node.second] + 1 + min_rot(rotation[node.first][node.second], map_rot[dir]) * 1000;
        }
        


    }

    cout << vals[res.first][res.second] << endl;
}

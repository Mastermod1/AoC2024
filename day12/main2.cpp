#include <bits/stdc++.h>

using namespace std;

bool in_range(int i, int j, int H, int W)
{
    return i >= 0 and j >= 0 and i < H and j < W;
}

vector<pair<int,int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfs(vector<vector<bool>>& vis, const vector<string>& v, int i, int j, int H, int W, char init, int& corners)
{
    if (not in_range(i, j, H, W)  or v[i][j] != init)
        return 0;
    if (vis[i][j])
        return 0;

    auto good = [&](int a, int b) {
        return in_range(a, b, H, W) and v[a][b] == init;
    };
    for (int k = 0; k < 4; k++)
    {
        auto a = make_pair(i + dirs[k].first, j + dirs[k].second);
        auto b = make_pair(i + dirs[(k+1)%4].first, j + dirs[(k+1)%4].second);
        if (not good(a.first, a.second) and not good(b.first, b.second))
            corners++;
        auto c = make_pair(i + dirs[k].first + dirs[(k+1)%4].first, j + dirs[k].second + dirs[(k+1)%4].second);
        if (good(a.first, a.second) and good(b.first, b.second) and not good(c.first, c.second))
            corners++;
    }

    vis[i][j] = true;
    int res = 1;
    res += dfs(vis, v, i + 1, j, H, W, init, corners);
    res += dfs(vis, v, i - 1, j, H, W, init, corners);
    res += dfs(vis, v, i, j + 1, H, W, init, corners);
    res += dfs(vis, v, i, j - 1, H, W, init, corners);

    return res;
}

int main(){
    string line = "";
    vector<string> v;
    while(getline(cin, line))
    {
        v.push_back(line);
    }
    int H = v.size();
    int W = v.front().length();
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    unsigned long long total = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int corners = 0;
            auto dd = dfs(visited, v, i, j, H, W, v[i][j], corners); 
            if (dd != 0)
            {
                total += dd * corners;
            }
        }
    }
    cout << total << endl;
}

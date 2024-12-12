#include <bits/stdc++.h>
#include <string>

using namespace std;

struct d
{
    int peri;
    int area;
    d& operator+=(const d& rhs)
    {
        peri += rhs.peri;
        area += rhs.area;
        return *this;
    }
};


bool in_range(int i, int j, int H, int W)
{
    return i >= 0 and j >= 0 and i < H and j < W;
}

d dfs(vector<vector<bool>>& vis, const vector<string>& v, int i, int j, int H, int W, char init)
{
    if (not in_range(i, j, H, W)  or v[i][j] != init)
        return d{1, 0};
    if (vis[i][j])
        return d{0, 0};

    vis[i][j] = true;
    d res {0, 1};
    res += dfs(vis, v, i + 1, j, H, W, init);
    res += dfs(vis, v, i - 1, j, H, W, init);
    res += dfs(vis, v, i, j + 1, H, W, init);
    res += dfs(vis, v, i, j - 1, H, W, init);

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
    // unordered_map<char, d> m;
    int total = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            auto dd = dfs(visited, v, i, j, H, W, v[i][j]); 
            total += dd.peri * dd.area;
        }
    }
    // for (auto x : m)
    //     total += x.second.area * x.second.peri;
        // cout << x.first << " " << x.second.area << " " << x.second.peri << endl;
    cout << total << endl;
}

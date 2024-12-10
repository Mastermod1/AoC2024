#include <bits/stdc++.h>

using namespace std;


bool in_range (int i, int j, int H, int W) {
    return i >= 0 and i < H and j >= 0 and j < W;
};

int trails (vector<vector<bool>>& vis, const vector<string>& v, int i, int j, int H, int W, char last = 47, int sum = 0)
{
    if (not in_range(i, j, H, W) or vis[i][j] or v[i][j] - last != 1)
        return 0;
    vis[i][j] = true;
    if (sum == 9 and v[i][j] == '9')
    {
        return 1;
    }
    else if (sum == 9)
        return 0;
    int res = 0;
    res += trails(vis, v, i + 1, j, H, W, v[i][j], sum + 1);
    res += trails(vis, v, i - 1, j, H, W, v[i][j], sum + 1);
    res += trails(vis, v, i , j + 1, H, W, v[i][j], sum + 1);
    res += trails(vis, v, i , j - 1, H, W, v[i][j], sum + 1);
    return res;

}


int main(){
    string line = "";
    vector<string> v;
    while(getline(cin, line))
    {
        v.push_back(line);
    }
    auto H = v.size();
    auto W = v.front().size();
    int count = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            vector<vector<bool>> vis(H, vector<bool>(W, false));
            if (v[i][j] == '0')
            {
                count += trails(vis, v, i, j, H, W);
            }
        }
    }
    cout << count << endl;
}

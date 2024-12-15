#include <bits/stdc++.h>

using namespace std;

bool not_in_range(pair<int, int> new_pos, int H, int W)
{
    return new_pos.first >= H or new_pos.first < 0 or new_pos.second >= W or new_pos.second < 0;
}

bool can_move(pair<int, int> curr, pair<int, int> dir, vector<string>& map, vector<vector<bool>>& vis, pair<int, int> prev = {-1, -1})
{
    auto np = make_pair(curr.first + dir.first, curr.second + dir.second);
    if (not_in_range(np, map.size(), map.front().length()))
        return false;
    if (map[np.first][np.second] == '#')
        return false;
    bool can = true;

    if (not vis[np.first][np.second] and map[np.first][np.second] == '[')
    {
        can = can and can_move(np, dir, map, vis, curr);
        vis[np.first][np.second] = true;
        can = can and can_move({np.first, np.second + 1}, dir, map, vis, curr);
        vis[np.first][np.second + 1] = true;
    }
    if (not vis[np.first][np.second] and map[np.first][np.second] == ']' and np != curr)
    {
        can = can and can_move(np, dir, map, vis, curr);
        vis[np.first][np.second] = true;
        can = can and can_move({np.first, np.second - 1}, dir, map, vis, curr);
        vis[np.first][np.second - 1] = true;
    }
    return can;
}

pair<int, int> move(pair<int, int> curr, pair<int, int> dir, vector<string>& map) {
    auto new_pos =  make_pair(curr.first + dir.first, curr.second + dir.second);
    vector<vector<bool>> checked(map.size(), vector<bool>(map.front().size(), false));
    if (not_in_range(new_pos, map.size(), map.front().length()) or  not_in_range(curr, map.size(), map.front().length()) or map[new_pos.first][new_pos.second] == '#' or not can_move(curr, dir, map, checked))
        return curr;
    pair<int, int> updated1{-1, -1}, updated2{-1, -1};
    char mark = map[new_pos.first][new_pos.second];
    if (mark == '[')
    {
        auto nex_new = make_pair(new_pos.first, new_pos.second + 1);
        updated1 = move(nex_new, dir, map);
        if (nex_new != updated1)
            updated1 = move(new_pos, dir, map);
        else
            updated1 = new_pos;
    }
    if (mark == ']')
    {
        auto nex_new = make_pair(new_pos.first, new_pos.second - 1);
        updated2 = move(nex_new, dir, map);
        if (nex_new != updated2)
            updated2 = move(new_pos, dir, map);
        else
            updated2 = new_pos;
    }
    if (updated1 != new_pos and updated2 != new_pos)
    {
        swap(map[curr.first][curr.second], map[new_pos.first][new_pos.second]);
        return new_pos;
    }
    return curr;
}

int main()
{
    vector<string> map;
    string line;
    while(getline(cin, line))
    {
        if (line == "")
            break;
        string new_line = "";
        for(auto x : line)
        {
            switch (x)
            {
                case '#':
                    new_line += "##";
                break;
                case '@':
                    new_line += "@.";
                break;
                case 'O':
                    new_line += "[]";
                break;
                case '.':
                    new_line += "..";
                break;
            }
        }
        map.push_back(new_line);
    }
    string moves;
    auto fpos = [&](){
        int y = 0;
        for (auto l : map)
        {
            for (int x = 0; x < l.length(); x++)
                if (l[x] == '@')
                    return make_pair(y, x);
            y++;
        }
    };
    auto pos = fpos();
    while (getline(cin, line))
        moves += line;
    for (auto m : moves)
    {
        // cout << m << endl;
        // for (auto l : map)
        // {
        //     for (int x = 0; x < l.length(); x++)
        //         printf("%c ", l[x]);
        //     printf("\n");
        // }
        switch (m)
        {
            case '^':
            {
                pair<int, int> dir = {-1, 0};
                pos = move(pos, dir, map);
                break;
            }
            case 'v':
            {
                pair<int, int> dir = {1, 0};
                pos = move(pos, dir, map);
                break;
            }
            case '>':
            {
                pair<int, int> dir = {0, 1};
                pos = move(pos, dir, map);
                break;
            }
            case '<':
            {
                pair<int, int> dir = {0, -1};
                pos = move(pos, dir, map);
                break;
            }
        }
    }
    int y = 0;
    int res = 0;
    cout << "Final\n";
    for (auto l : map)
    {
        for (int x = 0; x < l.length(); x++)
        {
            if (l[x] == '[')
                res += 100 * y + x;
            printf("%c ", l[x]);
        }
        y++;
        printf("\n");
    }
    cout << res << endl;
}

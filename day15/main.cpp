#include <bits/stdc++.h>

using namespace std;


pair<int, int> move(pair<int, int> curr, pair<int, int> dir, vector<string>& map) {
    auto new_pos =  make_pair(curr.first + dir.first, curr.second + dir.second);
    if (map[new_pos.first][new_pos.second] == '#')
        return curr;
    pair<int, int> updated;
    if (map[new_pos.first][new_pos.second] == 'O')
        updated = move(new_pos, dir, map);
    if (updated != new_pos)
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
        map.push_back(line);
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
    for (auto l : map)
    {
        for (int x = 0; x < l.length(); x++)
        {
            if (l[x] == 'O')
                res += 100 * y + x;
            printf("%c ", l[x]);
        }
        y++;
        printf("\n");
    }
    cout << res << endl;
}

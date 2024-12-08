#include <bits/stdc++.h>

using namespace std;

struct Pos
{
    pair<int, int> p;
    int dir_index;
};

bool operator==(const Pos& a, const Pos& b)
{
    return a.p == b.p and a.dir_index == b.dir_index;
}

struct pair_hash {
    inline std::size_t operator()(const Pos & v) const {
        return v.p.first*31+v.p.second;
    }
};

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
    auto pos_copy = pos;
    int sum = 0;
    vector<pair<int, int>> dirs = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int dir_index = 0;
    vector<Pos> path;
    auto is_valid = [&](auto pos) {
        return pos.first >= 0 and pos.second >= 0 and pos.first < H and pos.second < W;
    };
    while (is_valid(pos))
    {
        if (v[pos.first][pos.second] == '#')
        {
            pos.first += dirs[dir_index].first;
            pos.second -= dirs[dir_index].second;
            dir_index = (dir_index + 1)%4;
            continue;
        }
        path.push_back(Pos{pos, dir_index});
        pos.first -= dirs[dir_index].first;
        pos.second += dirs[dir_index].second;
    }
    for (int i = 0; i < path.size(); i++)
    {
        auto [poss, dir] = path[i];
        if (v[poss.first][poss.second] == '#')
            continue;

        dir_index = (dir + 1)%4;
        auto init_pos = poss;
        auto init_index = dir_index;
        auto added_hash = pair{init_pos.first - dir.first, init_pos.second + dir.second};
        if (is_valid(added_hash))
            v[added_hash.first][added_hash.second] = '#';


        unordered_set<Pos, pair_hash> visited;
        bool looped = false;
        // cout << "Test " << poss.first << " " << poss.second << endl;
        while (is_valid(poss)) 
        {
            // cout << poss.first << " " << poss.second << endl;
            if (visited.find(Pos{poss, dir_index}) != visited.end())
            {
                break;
            }
            visited.insert(Pos{poss, dir_index});
            if (v[poss.first][poss.second] == '#')
            {
                poss.first += dirs[dir_index].first;
                poss.second -= dirs[dir_index].second;
                visited.erase(Pos{poss, dir_index});
                dir_index = (dir_index + 1)%4;
                continue;
            }
            poss.first -= dirs[dir_index].first;
            poss.second += dirs[dir_index].second;
            if (poss == init_pos) 
            {
                // cout << "looped " << dir_index << " " << poss.first << " " << poss.second << endl;
                looped = true;
                break;
            }
        }
        // cout << "no cycle\n";
        if (is_valid(added_hash))
            v[added_hash.first][added_hash.second] = '.';
        if (looped)
        {
            // cout << init_pos.first << " " << init_pos.second << endl;
            sum++;
        }
    }
    cout << sum << endl;
}

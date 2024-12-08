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
    inline std::size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

struct pos_hash {
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
    auto start_pos = pos;
    int sum = 0;
    vector<pair<int, int>> dirs = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int dir_index = 0;
    unordered_set<pair<int, int>, pair_hash> path;
    auto is_valid = [&](auto pos) {
        return pos.first >= 0 and pos.second >= 0 and pos.first < H and pos.second < W;
    };
    while (is_valid(pos))
    {
        while (is_valid(pos) and v[pos.first][pos.second] == '#')
        {
            pos.first += dirs[dir_index].first;
            pos.second -= dirs[dir_index].second;
            dir_index = (dir_index + 1)%4;
            pos.first -= dirs[dir_index].first;
            pos.second += dirs[dir_index].second;
        }
        path.insert(pos);
        pos.first -= dirs[dir_index].first;
        pos.second += dirs[dir_index].second;
    }
    for (auto new_hash : path)
    {
        if (new_hash == start_pos)
            continue;
        v[new_hash.first][new_hash.second] = '#';
        pos = start_pos;
        dir_index = 0;
        unordered_set<Pos, pos_hash> visited;
        bool looped = false;
        while (is_valid(pos))
        {
            while (is_valid(pos) and v[pos.first][pos.second] == '#')
            {
                pos.first += dirs[dir_index].first;
                pos.second -= dirs[dir_index].second;
                dir_index = (dir_index + 1)%4;
                pos.first -= dirs[dir_index].first;
                pos.second += dirs[dir_index].second;
            }
            if (!visited.insert(Pos{pos, dir_index}).second)
            {
                looped = true;
                break;
            }
            pos.first -= dirs[dir_index].first;
            pos.second += dirs[dir_index].second;
        }
        v[new_hash.first][new_hash.second] = '.';
        if (looped)
            sum++;
    }
    cout << sum << endl;
}

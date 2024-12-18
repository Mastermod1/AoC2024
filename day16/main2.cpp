#include <bits/stdc++.h>

using namespace std;

struct State
{
    uint64_t cost;
    pair<int, int> pos;
    int dir;

    State(uint64_t cost_, pair<int, int> pos_, int dir_) : cost(cost_), pos(pos_), dir(dir_) {}

    bool operator>(const State& other) const { return cost > other.cost; }
};

pair<int, int> get_dir(int dir)
{
    switch (dir)
    {
        case 0:
            return make_pair(0, 1);
        case 1:
            return make_pair(1, 0);
        case 2:
            return make_pair(0, -1);
        case 3:
            return make_pair(-1, 0);
    }
    return make_pair(0, 0);
}

void dijkstra(const vector<string>& grid, const vector<State>& starts, map<pair<pair<int, int>, int>, uint64_t>& best)
{
    priority_queue<State, vector<State>, greater<State>> pq;
    for (const State& s : starts) pq.push(s);
    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();
        if (best.count(make_pair(cur.pos, cur.dir)) && cur.cost >= best[make_pair(cur.pos, cur.dir)]) continue;
        best[make_pair(cur.pos, cur.dir)] = cur.cost;
        pair<int, int> d = get_dir(cur.dir);
        if (grid[cur.pos.first + d.first][cur.pos.second + d.second] == '.')
        {
            pq.push(State(cur.cost + 1, make_pair(cur.pos.first + d.first, cur.pos.second + d.second), cur.dir));
        }
        pq.push(State(cur.cost + 1000, cur.pos, (cur.dir + 1) % 4));
        pq.push(State(cur.cost + 1000, cur.pos, (cur.dir + 3) % 4));
    }
}

int main()
{
    vector<string> grid;
    string line;
    while (getline(cin, line))
    {
        grid.push_back(line);
    }

    pair<int, int> start, end;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'S')
            {
                start = make_pair(i, j);
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'E')
            {
                end = make_pair(i, j);
                grid[i][j] = '.';
            }
        }
    }

    map<pair<pair<int, int>, int>, uint64_t> best_from_start;
    dijkstra(grid, {State(0, start, 0)}, best_from_start);

    map<pair<pair<int, int>, int>, uint64_t> best_from_end;
    vector<State> starts;
    for (int i = 0; i < 4; i++) starts.push_back(State(0, end, i));
    dijkstra(grid, starts, best_from_end);

    uint64_t goal = 99999999999999LL;
    for (int i = 0; i < 4; i++)
    {
        if (best_from_start.count(make_pair(end, i)))
        {
            goal = min(goal, best_from_start[make_pair(end, i)]);
        }
    }

    set<pair<int, int>> sols;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                pair<pair<int, int>, int> key_from_start = make_pair(make_pair(i, j), k);
                pair<pair<int, int>, int> key_from_end = make_pair(make_pair(i, j), (k + 2) % 4);
                if (!best_from_start.count(key_from_start) || !best_from_end.count(key_from_end)) continue;
                if (best_from_start[key_from_start] + best_from_end[key_from_end] == goal)
                {
                    sols.insert(make_pair(i, j));
                }
            }
        }
    }

    cout << sols.size() << endl;
    return 0;
}

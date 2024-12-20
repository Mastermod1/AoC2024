#include <bits/stdc++.h>

using namespace std;

struct hash_p
{
    size_t operator()(const pair<long long, long long>& a) const { return a.first * 31 + a.second; }
};

vector<pair<long long, long long>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(vector<vector<long long>>& dist, const vector<string>& track, pair<long long, long long> start)
{
    unordered_set<pair<long long, long long>, hash_p> vis;
    queue<pair<long long, long long>> q;
    q.push(start);
    long long distance = 0;
    while (not q.empty())
    {
        auto top = q.front();
        q.pop();
        vis.insert(top);
        dist[top.first][top.second] = distance;
        distance++;
        for (auto dir : dirs)
        {
            auto nw = make_pair(top.first + dir.first, top.second + dir.second);
            if (nw.first < 0 or nw.second < 0 or nw.first >= track.size() or nw.second >= track.front().size() or
                track[nw.first][nw.second] == '#' or vis.find(nw) != vis.end())
                continue;
            q.push(nw);
        }
    }
}

int main()
{
    string line;
    vector<string> track;
    pair<long long, long long> start;
    long long y = 0;
    while (getline(cin, line))
    {
        track.push_back(line);
        for (long long i = 0; i < line.length(); i++)
        {
            if (line[i] == 'S') start = make_pair(y, i);
        }
        y++;
    }
    long long h = track.size();
    long long w = track.front().length();
    vector<vector<long long>> distances(h, vector<long long>(w, -1));
    bfs(distances, track, start);
    forward_list<pair<int, int>> path;
    map<long long, long long> time_cnt;
    for (long long i = 0; i < h; i++)
    {
        for (long long j = 0; j < w; j++)
        {
            if (distances[i][j] != -1)
                path.emplace_front(i, j);
        }
    }
    for (auto src : path)
    {
        for (auto dst : path)
        {
            if (src == dst)
                continue;
            long long dist = abs(src.first - dst.first) + abs(src.second - dst.second);
            long long time = distances[dst.first][dst.second] - (distances[src.first][src.second] + dist);
            if (dist <= 20 and time > 0)
               time_cnt[time]++;
        }
    }
    long long res = 0;
    for (auto x : time_cnt)
        if (x.first >= 100)
            res += x.second;
    cout << res << endl;
}

#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
    return ((a % b) + b) % b;
}

// const int H = 7;
// const int W = 11;
const int H = 103;
const int W = 101;

struct obj
{
    long long x;
    long long y;
    long long vx;
    long long vy;
};

int main()
{
    long long time = 100;
    string line;
    ifstream f("input");
    vector<obj> v;
    while (getline(f, line))
    {
        stringstream ss(line);
        long long x, y, dx, dy;
        ss.ignore(2);
        char deli;
        ss >> x >> deli >> y;
        ss.ignore(3);
        ss >> dx >> deli >> dy;
        v.push_back(obj{x, y, dx, dy});
    }

    
    time = 0;
    while (true)
    {
        time++;
        int cnt = 0;
        bool valid = true;
        int area[H][W] = {0};
        set<pair<long long, long long>> s;
        for (auto& o : v)
        {
            auto [x, y, dx, dy] = o;
            long long fx = (x + time * dx);
            fx = mod(fx, W);
            long long fy = (y + time * dy);
            fy = mod(fy, H);

            x = fx;
            y = fy;
            area[y][x]++;
            if (not s.insert({x, y}).second)
            {
                valid = false;
                break;
            }

        }
        if (valid)
        {
            printf("For %d\n", time);
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    printf("%d ", area[i][j]);
                }
                printf("\n");
            }
            break;
        }
    }


    cout << time << endl;
}

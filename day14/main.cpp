#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
    return ((a % b) + b) % b;
}

// const int H = 7;
// const int W = 11;
const int H = 103;
const int W = 101;

int main()
{
    long long area[H][W] = {0};
    long long time = 100;
    string line;
    long long q[4] = {0};
    while (getline(cin, line))
    {
        stringstream ss(line);
        long long x, y, dx, dy;
        ss.ignore(2);
        char deli;
        ss >> x >> deli >> y;
        ss.ignore(3);
        ss >> dx >> deli >> dy;
        long long fx = (x + time * dx);
        fx = mod(fx, W);
        long long fy = (y + time * dy);
        fy = mod(fy, H);

        area[fy][fx]++;
        x = fx;
        y = fy;

        if (x == W / 2 or y == H / 2)
            continue;
        auto id = int(x > W / 2) + int(y > H / 2) * 2;
        q[id]++;
    }

    cout << q[0] * q[1] * q[2] * q[3] << endl;
}

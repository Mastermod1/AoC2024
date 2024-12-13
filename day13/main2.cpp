#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long tokens = 0;
    for (int i = 0; i < 320; i++)
    {
        long long ax, ay, bx, by, gx, gy;
        cin >> ax >> ay >> bx >> by >> gx >> gy;
        gx += 10000000000000;
        gy += 10000000000000;
        auto resB = (gy * ax - gx * ay) / (by * ax - bx * ay);
        auto resA = (gx - bx * resB) / ax;
        if (resA >= 0 and resB >= 0 and resA * ax + resB * bx == gx and resA * ay + resB * by == gy)
            tokens += 3 * resA + resB;
    }
    cout << tokens << endl;
}

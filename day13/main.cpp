#include <bits/stdc++.h>

using namespace std;

int main(){
    auto tokens = 0;
    for (int i = 0; i < 320; i++)
    {
        int ax, ay, bx, by, gx, gy;
        cin >> ax >> ay >> bx >> by >> gx >> gy;
        auto resB = (gy * ax - gx * ay) / (by * ax - bx * ay);
        auto resA = (gx - bx * resB) / ax;
        // cout << resA << " " << resB << endl;
        // cout << resA * ax + resB * bx << " " << resA * ay + resB * by << endl;
        cout << resA <<  " " << resB << endl;
        if (resA * ax + resB * bx == gx and resA * ay + resB * by == gy)
            tokens += 3 * resA + resB;
    }
    cout << tokens << endl;
}

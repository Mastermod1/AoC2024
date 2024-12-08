#include <bits/stdc++.h>

using namespace std;

int main() {
    int safe_cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        bool safe = true;
        int flag = 0;
        string line = "";
        getline(cin, line);
        istringstream stream(line);
        int prev;
        stream >> prev;
        int curr;
        while (stream >> curr) 
        {
            int diff = abs(prev - curr);
            if (diff < 1 or diff > 3)
                flag |= 4;
            if (prev < curr )
                flag |= 1;
            if (prev > curr)
                flag |= 2;
            prev = curr;
        }
        if (flag == 1 or flag == 2)
        {
            safe_cnt++;
        }
    }    
    cout << safe_cnt << endl;
}

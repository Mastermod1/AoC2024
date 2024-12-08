#include <bits/stdc++.h>

using namespace std;

bool in_range(int val)
{
    return val >= 1 and val <= 3;
}

bool isOk(const std::vector<int>& v)
{
    bool is_inc = true;
    bool is_dec = true;
    bool in_range = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int diff = v[i + 1] - v[i];
        int difff = abs(diff);
        if (difff < 1 or difff > 3)
        {
            in_range = false;
            break;
        }
        if (diff > 0) is_dec = false;
        if (diff < 0) is_inc = false;
    }
    return (is_dec or is_inc) and in_range;
}

bool try_remove(int pos, std::vector<int>& v)
{
    vector<int> vv = v;
    vv.erase(vv.begin() + pos);
    return isOk(vv);
}

int main() {
    int safe_cnt = 0;
    for (int i = 0; i < 1000; i++)
    {
        string line = "";
        getline(cin, line);
        istringstream stream(line);
        vector<int> v;
        int curr;
        while (stream >> curr) 
        {
            v.push_back(curr);
        }

        bool any_ok = false;
        any_ok = any_ok or try_remove(0, v);
        for (int i = 0; i < v.size() - 1; i++)
        {
            int diff = v[i + 1] - v[i];
            if (abs(diff) < 1 or abs(diff) > 3)
            {
                any_ok = any_ok or try_remove(i, v);
                any_ok = any_ok or try_remove(i + 1, v);
                break;
            }

            if (i + 2 < v.size())
            {
                int diff2 = v[i+2] - v[i+1];
                if ((diff > 0) != (diff2 > 0))
                {
                    any_ok = any_ok or try_remove(i, v);
                    any_ok = any_ok or try_remove(i + 1, v);
                    any_ok = any_ok or try_remove(i + 2, v);
                    break;
                }
            }

        }
        if (any_ok)
            safe_cnt++;
    }    
    cout << safe_cnt << endl;
}

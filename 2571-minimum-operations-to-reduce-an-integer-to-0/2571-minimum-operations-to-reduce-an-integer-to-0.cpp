class Solution
{
public:
    int minOperations(int n)
    {
        vector<int> v;
        int o = 0, z = 0;

        int fv = 0;
        if(n & 1) fv = 1;

        while(n)
        {
            if(n & 1) o++, v.push_back(1);
            else z++, v.push_back(0);
            n >>= 1;
        }

        int res1 = min(o, z + 2);
        // cout << res1 << endl;
        // for(auto e : v) cout << e << " "; cout << endl;

        int cc = 1;
        int pv = fv;

        vector<pair<int, int>> vv;  // {value, count}

        for(int i = 1; i < v.size(); i++)
        {
            if(v[i] == pv)
            {
                cc++;
            }
            else
            {
                vv.push_back({pv, cc});
                cc = 1;
                pv = v[i];
            }
        }

        vv.push_back({pv, cc});

        // for(auto e : vv) cout << e.first << "," << e.second << " "; cout << endl;

        // current value zero, prev and next are there 1 with atleast one's occ > 1

        int ct = 0;

        for(int i = 1; i < vv.size() - 1; i++)
        {
            if(vv[i].first == 0 && vv[i].second == 1)
            {
                if(vv[i - 1].second > 1 || vv[i + 1].second > 1)
                {
                    vv[i].first = 1;
                    ct++;
                }
            }
        }

        // for(auto e : vv) cout << e.first << "," << e.second << " "; cout << endl;
        int res2 = ct;

        for(int i = 0; i < vv.size(); i++) {
            if(vv[i].first == 1) {
                int fq = 0;
                while(i < vv.size() && vv[i].first == 1) fq += vv[i].second, i++;
                res2 += min(fq, 2);
            }
        }

        return min(res1, res2);
    }
};
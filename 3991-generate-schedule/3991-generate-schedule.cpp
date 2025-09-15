class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        int nono = (n / 2) + 1;

        int ss = 1;

        vector<vector<int>> res;
        set<pair<int, int>> s;

        if(n <= 4) return res;

        while(ss < nono)
        {
            int i = 0, j = i + ss;

            while(true)
            {
                i %= n; j %= n;

                if(s.find({i, j}) != s.end())
                {
                    if(s.find({j, i}) != s.end())
                    {
                        break;
                    }
                    else
                    {
                        res.push_back({j, i});
                        s.insert({j, i});
                    }
                }
                else
                {
                    res.push_back({i, j});
                    s.insert({i, j});
                }

                if(ss == 1) { i += 2; j += 2; }
                else { i++; j++; }
            }

            ss++;
        }

        int li = res.back()[0];
        int lj = res.back()[1];

        // int sss = 1;
        int i = 1, j = 2;

        while(i == li || i == lj || j == li || j == lj) { i+=2; j+=2; }

        while(true)
        {
            i %= n; j %= n;

            if(s.find({i, j}) != s.end())
            {
                if(s.find({j, i}) != s.end())
                {
                    break;
                }
                else
                {
                    res.push_back({j, i});
                    s.insert({j, i});
                }
            }
            else
            {
                res.push_back({i, j});
                s.insert({i, j});
            }

            i += 2; j += 2;
        }

        // cout << res.size() << endl;

        return res;
    }
};
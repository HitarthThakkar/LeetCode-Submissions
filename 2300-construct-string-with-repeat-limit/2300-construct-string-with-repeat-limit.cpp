class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        map<char, int> m; string ans = "";
        for(auto ele : s) m[ele]++;
        while(m.size() > 1)
        {
            auto it = m.end(); it--;
            char lc = it->first; int lf = it->second; it--; char slc = it->first;
            if(lf > repeatLimit)
            {
                for(int i = 0; i < repeatLimit; i++) ans += lc;
                it++; it->second -= repeatLimit;
                it--; it->second--;
                if(it->second == 0) m.erase(it);
                ans += slc;
            }
            else
            {
                for(int i = 0; i < lf; i++) ans += lc;
                it++; m.erase(it);
            }
        }
        int times = min(m.begin()->second, repeatLimit);
        while(times--) ans += (m.begin()->first);
        return ans;
    }
};
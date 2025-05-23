#define pai pair<int, int>
class Solution
{
public:
    int minTaps(int n, vector<int>& ranges)
    {
        vector<pair<int, int>> vp;
        for(int i = 0; i < n + 1; i++)
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            vp.push_back({left, right});
        }

        auto cmp = [] (const pai &a, const pai &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(vp.begin(), vp.end(), cmp);

        // for(auto p : vp) cout << p.first << " " << p.second << endl;

        int lastTakenIndex = 0;
        int taps = 1;

        while(true)
        {
            if(vp[lastTakenIndex].second == n) return taps;

            int mexStart = vp[lastTakenIndex].second;
            int LegacyIndex = lastTakenIndex;
            int i = lastTakenIndex + 1;

            while(i < (n + 1) && vp[i].first <= mexStart)
            {
                if(vp[i].second > vp[LegacyIndex].second) LegacyIndex = i;
                i++;
            }

            if(LegacyIndex == lastTakenIndex) return -1;

            taps++;
            lastTakenIndex = LegacyIndex;
        }

        return taps;
    }
};
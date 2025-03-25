#define pai pair<int, int>
class Solution
{
private:
    bool isGood(vector<pai> &vp)
    {
        int count = 0;
        int maxReach = vp[0].second;
        for(int i = 1; i < vp.size(); i++)
        {
            if(vp[i].first >= maxReach) { count++; maxReach = vp[i].second; }
            else { maxReach = max(maxReach, vp[i].second); }
        }
        return (count > 1);
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles)
    {
        vector<pai> x, y;
        for(auto r : rectangles)
        {
            x.push_back({r[0], r[2]});
            y.push_back({r[1], r[3]});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return (isGood(x) || isGood(y));
    }
};
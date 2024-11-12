class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        map<int, int> m; vector<int> ans;
        for(auto ele : items) m[ele[0]] = max(m[ele[0]], ele[1]);
        int prev = -1;
        for(auto &ele : m) ele.second = max(ele.second, prev), prev = ele.second;
        for(auto ele : queries)
        {
            auto it = m.upper_bound(ele);
            if(it == m.begin()) ans.push_back(0); else it--, ans.push_back(it->second);
        }
        return ans;
    }
};
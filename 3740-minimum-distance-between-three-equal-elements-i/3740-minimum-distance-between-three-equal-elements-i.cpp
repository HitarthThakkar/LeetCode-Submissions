class Solution
{
public:
    int minimumDistance(vector<int>& nums)
    {
        int res = 1e9;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);

        for(auto e : mp)
        {
            if(e.second.size() > 2)
            {
                for(int i = 0; i < e.second.size() - 2; i++)
                {
                    res = min(res, e.second[i + 2] - e.second[i]);
                }
            }
        }

        return (res == 1e9 ? -1 : 2 * res);
    }
};
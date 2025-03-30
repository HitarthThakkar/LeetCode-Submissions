class Solution
{
public:
    map<int, vector<int>> mp;
    Solution(vector<int>& nums)
    {
        int i = 0;
        for(auto e : nums) mp[e].push_back(i++);
    }
    int pick(int target)
    {
        int sz = mp[target].size();
        int r = rand() % sz;
        return mp[target][r];
    }
};
class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        int n = nums.size();
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) m[nums[i]].push_back(i);
        set<int> s;
        int ans = 0;
        for(auto e : m)
        {
            if(e.first == 0)
            {
                for(auto ee : e.second) s.insert(ee);
            }
            else
            {
                set<int> uniq;
                for(auto ee : e.second)
                {
                    auto it = s.lower_bound(ee);
                    if(it == s.end()) uniq.insert(1e6);
                    else uniq.insert(*it);
                    s.insert(ee);
                }
                ans += uniq.size();
            }
        }
        return ans;
    }
};
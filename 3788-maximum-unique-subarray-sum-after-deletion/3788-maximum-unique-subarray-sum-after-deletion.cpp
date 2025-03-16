class Solution {
public:
    int maxSum(vector<int>& nums)
    {
        int neg = 0, pos = 0, z = 0;
        for(auto e : nums)
        {
            if(e < 0) neg++;
            else if(e > 0) pos++;
            else z++;
        }
        if(pos == 0)
        {
            if(z == 0)
            {
                int ans = -1e9;
                for(auto e : nums)
                    if(e < 0) ans = max(ans, e);
                return ans;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            int n = nums.size();
            int ans = 0;
            set<int> s;
            for(auto e : nums)
                {
                    if(e > 0 && s.find(e) == s.end())
                    {
                        ans += e;
                        s.insert(e);
                    }
                }
            return ans;
        }
    }
};
class Solution
{
public:

    int reverse(int n)
    {
        int res = 0;
        while(n) {
            res = (res * 10) + (n % 10);
            n /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int res = 1e9;

        for(int i = 0; i < n; i++)
        {
            int rev = reverse(nums[i]);
            if(mp.find(rev) != mp.end())
            {
                int ind = upper_bound(mp[rev].begin(), mp[rev].end(), i) - mp[rev].begin();
                if(ind >= 0 && ind < mp[rev].size()) res = min(res, mp[rev][ind] - i);
            }
        }

        return (res == 1e9 ? -1 : res);
    }
};
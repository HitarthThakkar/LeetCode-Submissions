class Solution {
public:

    long long int rev(long long int n)
    {
        string s = "";
        while(n)
            {
                if(n & 1) s += "1";
                else s += "0";
                n /= 2;
            }

        long long int res = 0;
        long long int mul = 1;

        while(s.length() > 0)
            {
                int cur = (s[s.length() - 1] == '1' ? 1 : 0);
                res += (mul * cur);
                mul *= 2;
                s.pop_back();
            }

        return res;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long int, long long int>> vp;
        for(int i = 0; i < n; i++)
            {
                long long int ii = rev(nums[i]);
                vp.push_back({ii, nums[i]});
            }
        sort(vp.begin(), vp.end());
        vector<int> res;
        for(auto e : vp) res.push_back(e.second);
        return res;
    }
};
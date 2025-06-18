class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> pfx, sfx;
        int prev = 1, prev2 = 1;
        for(int i = 0; i < n; i++)
        {
            pfx.push_back(prev * nums[i]);
            sfx.push_back(prev2 * nums[n - i - 1]);
            prev = pfx.back();
            prev2 = sfx.back();
        }
        // for(auto e : pfx) cout << e << " "; cout << endl;
        // for(auto e : sfx) cout << e << " ";
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int ans = 1;
            if(i > 0) ans *= pfx[i - 1];
            if(i < n - 1) ans *= sfx[n - i - 2];
            res.push_back(ans);
        }
        return res;
    }
};
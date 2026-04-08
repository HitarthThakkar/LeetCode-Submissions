class Solution
{
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int m = 1e9 + 7;

        for(auto q : queries)
        {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for(int i = l; i <= r; i += k)
            {
                nums[i] = ((nums[i] % m) * 1LL * (v % m)) % m;
            }
        }

        int xr = 0;
        for(auto e : nums) xr ^= e;
        return xr;
    }
};
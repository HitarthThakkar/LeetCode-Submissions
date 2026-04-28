#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution
{
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        vector<int> nums;
        nums.reserve(total);

        int base = grid[0][0];
        int base_mod = base % x;

        // Flatten + check feasibility + normalize
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int e = grid[i][j];
                if (e % x != base_mod)
                    return -1;
                nums.push_back((e - base) / x);
            }
        }

        // Find median
        int mid = total >> 1;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        // Compute result
        int res = 0;
        for (int i = 0; i < total; ++i)
            res += abs(nums[i] - median);

        return res;
    }
};
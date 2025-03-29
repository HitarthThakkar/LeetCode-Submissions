class Solution
{
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        // 2025 Hiring Prep Sprint Week_2 Q6
        int n = nums.size();
        vector<int> pfx(n, 0);
        for(auto q : queries) {
            pfx[q[0]]--;
            if(q[1] < n - 1) pfx[q[1] + 1]++;
        }
        for(int i = 1; i < n; i++) pfx[i] += pfx[i - 1];
        for(int i = 0; i < n; i++) if(nums[i] + pfx[i] > 0) return false;
        return true;
    }
};
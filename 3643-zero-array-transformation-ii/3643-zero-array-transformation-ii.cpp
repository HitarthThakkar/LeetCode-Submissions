class Solution
{
private:
    bool good(int k, vector<vector<int>> &queries, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pfx(n, 0);
        for(int i = 0; i < k; i++) {
            pfx[queries[i][0]] -= queries[i][2];
            if(queries[i][1] < n - 1) pfx[queries[i][1] + 1] += queries[i][2];
        }
        for(int i = 1; i < n; i++) pfx[i] += pfx[i - 1];
        for(int i = 0; i < n; i++) if(nums[i] + pfx[i] > 0) return false;
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        int q = queries.size();
        int lo = 0;
        int hi = q;
        int answer = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(good(mid, queries, nums))
            {
                answer = mid;
                hi = mid - 1; 
            }
            else
            {
                lo = mid + 1;
            }
        }
        return answer;
    }
};
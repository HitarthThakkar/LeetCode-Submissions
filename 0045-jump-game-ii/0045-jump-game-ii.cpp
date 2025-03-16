class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int maxReach = 0; int lastIndex = 0; int jumps = 0;
        if(n == 1) return 0;
        for(int i = 0; i < n; i++)
        {
            maxReach = max(maxReach, i + nums[i]);
            if(i == lastIndex)
            {
                if(i == maxReach) return -1; // Won't happen
                lastIndex = maxReach;
                jumps++;
                if(maxReach >= n - 1) return jumps;
            }
        }
        return 1e9;
    }
};
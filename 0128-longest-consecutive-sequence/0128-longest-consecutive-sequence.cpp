class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        while(i < n)
        {
            int j = i + 1;
            int trashCount = 0;
            while(j < n)
            {
                if(nums[j] == nums[j - 1] + 1)
                    j++;
                else if (nums[j] == nums[j - 1])
                    trashCount++, j++;
                else break;
            }
            ans = max(ans, j - i - trashCount);
            i = j;
        }
        return ans;
    }
};
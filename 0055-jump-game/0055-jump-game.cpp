class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        // 2025 Hiring Prep Sprint Week_3 Q5
        // 30th March 2025 POTD (playing BGM - smth in common)
        int myMaxReach = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; i++)
        {
            if (i <= myMaxReach) myMaxReach = max(myMaxReach, i + nums[i]);
            else return false;
            if (myMaxReach > n - 2) return true;
        }

        return (myMaxReach > n - 2);
    }
};
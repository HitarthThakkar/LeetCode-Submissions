class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int n = nums.size();

        int one = 1, two = 1;
        int running = 1, running2 = 1;

        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] < nums[i + 1])
            {
                running++;
            }
            else
            {
                running = 1;
            }

            if(nums[i] > nums[i + 1])
            {
                running2++;
            }
            else
            {
                running2 = 1;
            }

            one = max(one, running);
            two = max(two, running2);
        }

        return max(one, two);
    }
};
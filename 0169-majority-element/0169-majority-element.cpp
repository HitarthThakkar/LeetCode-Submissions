class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        // Boyer - Moore Voting Algorithm
        int ele = -1, ct = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(ct == 0)
                ct++, ele = nums[i];
            else if(nums[i] == ele)
                ct++;
            else
                ct--;
        }
        return ele;
    }
};
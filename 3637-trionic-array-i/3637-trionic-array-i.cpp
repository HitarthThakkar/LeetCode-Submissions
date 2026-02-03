class Solution
{
public:
    bool isTrionic(vector<int>& nums)
    {
        int n = nums.size();
        int prev = 0;
        bool vis1 = false;
        bool vis2 = false;

        for(int i = 1; i < n - 1; i++)
        {
            if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                if(prev == 0 || prev == 1 || prev == 4) prev = 1;
                else return false;
            }
            else if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            {
                if((prev == 0 || prev == 1) && (!vis1) && (!vis2)) { prev = 2; vis1 = true; }
                else return false;
            }
            else if(nums[i - 1] > nums[i] && nums[i] > nums[i + 1])
            {
                if(prev == 2 || prev == 3) prev = 3;
                else return false;
            }
            else if(nums[i - 1] > nums[i] && nums[i] < nums[i + 1])
            {
                if((prev == 2 || prev == 3) && (vis1) && (!vis2)) { prev = 4; vis2 = true; }
                else return false;
            }
            else return false;
        }

        return (vis1 & vis2);
    }
};
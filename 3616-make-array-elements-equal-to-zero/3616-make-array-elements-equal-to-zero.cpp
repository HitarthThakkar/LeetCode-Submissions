class Solution
{
public:
    int countValidSelections(vector<int>& nums)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int pfx = 0, res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                int delta = abs(pfx - (totalSum - pfx));
                if(delta == 0) res += 2;
                else if(delta == 1) res++;
            }
            pfx += nums[i];
        }
        return res;
    }
};
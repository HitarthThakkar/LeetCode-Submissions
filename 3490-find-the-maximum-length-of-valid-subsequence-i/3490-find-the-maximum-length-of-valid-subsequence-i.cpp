class Solution
{
public:
    int maximumLength(vector<int>& nums)
    {
        int odd = 0, ev = 0;
        for(auto ele : nums) if(ele & 1) odd++; else ev++;
        int pos1 = max(odd, ev);

        int pos2 = 0, lastParity = (nums[0] & 1 ? 1 : 0);

        for(int i = 1; i < nums.size(); i++)
        {
            if(lastParity == 0 && (nums[i] & 1))
            {
                lastParity = 1;
                pos2++;
            }
            else if(lastParity == 1 && (nums[i] % 2 == 0))
            {
                lastParity = 0;
                pos2++;
            }
        }

        return max(pos1, pos2 + 1);
    }
};
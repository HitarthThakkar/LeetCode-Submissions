class Solution
{
public:
    int scoreDifference(vector<int>& nums)
    {
        bool turn = true;   // true = first player, false = second player
        int fps = 0;
        int sps = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & 1) turn = !turn;
            if(i % 6 == 5) turn = !turn;

            if(turn) fps += nums[i];
            else sps += nums[i];
        }

        return (fps - sps);
    }
};
class Solution
{
public:
    int giveOps(vector<int> &nums, int target)
    {
        int ops = 0;
        int lt = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(lt == -1) { lt = i; }
                else { ops += (i - lt); lt = -1; }
            }   
        }
        return ops;
    }
    bool canMakeEqual(vector<int>& nums, int k)
    {
        int one = 0;
        int mone = 0;
        for(auto e : nums) if(e == 1) one++; else mone++;
        if(one & 1 && mone & 1) return false;
        if(one & 1) return (giveOps(nums, -1) <= k);
        else if(mone & 1) return (giveOps(nums, 1) <= k);
        else return ((giveOps(nums, -1) <= k) || (giveOps(nums, 1) <= k));
    }
};
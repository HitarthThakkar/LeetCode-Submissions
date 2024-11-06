class Solution
{
public:
    bool canSortArray(vector<int>& nums)
    {
        vector<int> bpc(nums.size());
        for (int i = 0; i < nums.size(); i++) bpc[i] = __builtin_popcount(nums[i]);
        vector<int> v;
        int mexi = nums[0], mini = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (bpc[i - 1] != bpc[i]) {
                v.push_back(mini); v.push_back(mexi);
                mini = nums[i]; mexi = nums[i];
            }
            else {
                if (nums[i] > mexi) mexi = nums[i];
                if (nums[i] < mini) mini = nums[i];
            }
        }
        v.push_back(mini); v.push_back(mexi);
        for (int i = 0; i < v.size() - 1; i++) if (v[i] > v[i + 1]) return false;
        return true;
    }
};
class Solution
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int> res = nums;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == pivot)
            {
                pivot = i;
                break;
            }
        }

        int less = 0, equal = 0;
        for(auto &ele : nums)
        {
            if(ele < nums[pivot]) less++;
            else if(ele == nums[pivot]) equal++;
        }

        int spl = 0;
        int speq = less;
        int spg = speq + equal;

        for(auto &ele : nums)
        {
            if(ele < nums[pivot]) res[spl++] = ele;
            else if(ele > nums[pivot]) res[spg++] = ele;
            else res[speq++] = ele;
        }

        return res;
    }
};
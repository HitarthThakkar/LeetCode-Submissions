class Solution
{
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for(int sp = 0; sp < n - k + 1; sp++)
        {
            if(ans.size() > 0 && ans.back() != -1 && k != 1)
            {
                int li = sp + k - 1;
                if(nums[li] - 1 == nums[li - 1]) ans.push_back(nums[li]);
                else ans.push_back(-1);
            }
            else
            {
                bool good = true;
                for(int i = sp; i < sp + k - 1; i++)
                    if(nums[i + 1] - 1 != nums[i]) { good = false; break; }
                if(good) ans.push_back(nums[sp + k - 1]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};
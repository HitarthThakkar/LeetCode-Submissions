class Solution
{
private:
    bool isGood(int limit, vector<int> &nums, int k)
    {
        bool prev = false;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] <= limit && !prev) k--, prev = true; else prev = false;
        return (k < 1);
    }
public:
    int minCapability(vector<int>& nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int answer = r;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(isGood(mid, nums, k)) answer = mid, r = mid - 1;
            else l = mid + 1;
        }
        return answer;
    }
};
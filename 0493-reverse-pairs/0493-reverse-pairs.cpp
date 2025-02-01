class Solution
{
private:
    void merge(int lo, int mid, int hi, vector<long long int>& nums)
    {
        int p1 = lo, p2 = mid + 1;
        vector<int> v;
        while(p1 < (mid + 1) && p2 < (hi + 1))
            if(nums[p1] < nums[p2]) v.push_back(nums[p1++]);
            else v.push_back(nums[p2++]);
        while(p1 < (mid + 1)) v.push_back(nums[p1++]);
        while(p2 < (hi + 1)) v.push_back(nums[p2++]);
        for(int i = lo; i <= hi; i++) nums[i] = v[i - lo];
    }
    int recur(int lo, int hi, vector<long long int>& nums)
    {
        if(lo >= hi) return 0;
        int mid = (lo + hi) / 2;
        int ans = recur(lo, mid, nums);
        ans += recur(mid + 1, hi, nums);
        int j = mid + 1;
        for(int i = lo; i <= mid; i++)
        {
            while(j < (hi + 1) && (2 * nums[j]) < nums[i]) j++;
            ans += (j - mid - 1);
        }
        merge(lo, mid, hi, nums);
        return ans;
    }
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        vector<long long int> numss;
        for(auto ele : nums) numss.push_back(ele);
        return recur(0, n - 1, numss);
    }
};
class Solution
{
private:
    vector<int> giveLIS(vector<int> &nums)
    {
        vector<int> v, lis;
        for(auto e : nums)
        {
            if(v.empty()) v.push_back(e);
            if(e > v.back()) v.push_back(e);
            else { int ind = lower_bound(v.begin(), v.end(), e) - v.begin(); v[ind] = e; }
            lis.push_back(v.size());
        }
        return lis;
    }
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> LIS = giveLIS(nums);
        // for(auto e : LIS) cout << e << " "; cout << endl;
        reverse(nums.begin(), nums.end());
        vector<int> LDS = giveLIS(nums);
        reverse(LDS.begin(), LDS.end());
        // for(auto e : LDS) cout << e << " "; cout << endl;
        int mini = 1e9;
        for(int i = 1; i < n - 1; i++)
            if(LIS[i] > 1 && LDS[i] > 1) mini = min(mini, n - LIS[i] - LDS[i] + 1);
        return mini;
    }
};
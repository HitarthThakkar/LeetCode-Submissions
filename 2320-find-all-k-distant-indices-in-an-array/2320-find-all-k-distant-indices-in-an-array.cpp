class Solution
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        int n = nums.size();
        vector<int> indices;
        for(int i = 0; i < n; i++) if(nums[i] == key) indices.push_back(i);
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            int lbi = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int mindis = 1e9;
            if(lbi > 0) mindis = min(mindis, abs(i - indices[lbi - 1]));
            if(lbi != indices.size()) mindis = min(mindis, abs(indices[lbi] - i));
            else mindis = min(mindis, i - indices.back());
            if(mindis <= k) result.push_back(i);
        }
        return result;
    }
};
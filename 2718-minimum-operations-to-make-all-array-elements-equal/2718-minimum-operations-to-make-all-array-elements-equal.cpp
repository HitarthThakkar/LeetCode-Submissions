class Solution
{
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pfx(n, nums[0]), sfx(n, nums[n - 1]);
        for(int i = 1; i < n; i++) pfx[i] = pfx[i - 1] + nums[i];
        for(int i = n - 2; i >= 0; i--) sfx[i] = sfx[i + 1] + nums[i];
        vector<long long> answer;
        for(auto q : queries)
        {
            auto it = lower_bound(nums.begin(), nums.end(), q);
            if(it == nums.end())
            {
                long long int diff = ((n * 1LL * q) - pfx.back());
                answer.push_back(diff);
            }
            else
            {
                int ind = it - nums.begin();
                long long int diff = (sfx[ind] - ((n - ind) * 1LL * q));
                if(ind > 0) diff += ((q * 1LL * ind) - (pfx[ind - 1]));
                answer.push_back(diff);
            }
        }
        return answer;
    }
};
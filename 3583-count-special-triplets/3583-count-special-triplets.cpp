class Solution
{
public:
    int specialTriplets(vector<int>& nums)
    {
        unordered_map<int, int> left, right;
        for(auto e : nums) right[e]++;

        long long int res = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++)
        {
            // remove nums[i] from right
            right[nums[i]]--;
            if(right[nums[i]] == 0) right.erase(nums[i]);

            // calculate pairs
            int target = nums[i] * 2;
            long long int leftCount = 0, rightCount = 0;
            if(left.find(target) != left.end()) leftCount = left[target];
            if(right.find(target) != right.end()) rightCount = right[target];

            res = ((res % mod) + (((leftCount % mod) * (rightCount % mod)) % mod)) % mod;

            // add nums[i] to left
            left[nums[i]]++;
        }

        return res;
    }
};
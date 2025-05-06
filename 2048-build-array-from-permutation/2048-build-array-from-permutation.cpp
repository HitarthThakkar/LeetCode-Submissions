class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        for(auto e : nums) result.push_back(nums[e]);
        return result;
    }
};
class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int target = nums[n / 2];
        int answer = 0;
        for(auto e : nums)
            answer += abs(e - target);
        return answer;
    }
};
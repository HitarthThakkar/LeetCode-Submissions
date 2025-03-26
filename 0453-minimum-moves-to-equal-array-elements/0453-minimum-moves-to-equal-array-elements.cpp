class Solution
{
public:
    int minMoves(vector<int>& nums)
    {
        int mini = *min_element(nums.begin(), nums.end());
        int answer = 0;
        for(auto e : nums) answer += (e - mini);
        return answer;
    }
};
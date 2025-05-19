class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int one = nums[0];
        int two = nums[1];
        int three = nums[2];
        if(one + two <= three) return "none";
        if(one == two && two == three) return "equilateral";
        if(one == two || two == three || one == three) return "isosceles";
        return "scalene";
    }
};
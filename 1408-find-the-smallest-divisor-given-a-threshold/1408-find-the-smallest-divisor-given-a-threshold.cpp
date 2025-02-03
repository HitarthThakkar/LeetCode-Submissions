class Solution
{
private:
    long long int sumWhenDivisorIsMid(int divisor, vector<int>& nums)
    {
        long long int sum = 0;
        for(auto num : nums)
        {
            if(num <= divisor) { sum++; }
            else { if(num % divisor != 0) sum++; sum += (num / divisor); }
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int min_divisor = 1;
        int max_divisor = *max_element(nums.begin(), nums.end());
        int optimal_divisor = max_divisor;
        while(min_divisor <= max_divisor)
        {
            int mid_divisor = (min_divisor + max_divisor) / 2;
            if(sumWhenDivisorIsMid(mid_divisor, nums) <= threshold)
            {
                optimal_divisor = min(optimal_divisor, mid_divisor);
                max_divisor = mid_divisor - 1;
            }
            else
            {
                min_divisor = mid_divisor + 1;
            }
        }
        return optimal_divisor;
    }
};
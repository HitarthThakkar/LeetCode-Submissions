class Solution
{
private:
    void updateBitCounts(vector<int>& bitCounts, int number, int delta)
    {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) if ((number >> bitPosition) & 1) bitCounts[bitPosition] += delta;
    }
    int convertBitCountsToNumber(const vector<int>& bitCounts)
    {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) if (bitCounts[bitPosition] != 0) result |= 1 << bitPosition;
        return result;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int minLength = INT_MAX, windowStart = 0, windowEnd = 0;
        vector<int> bitCounts(32, 0);

        while (windowEnd < nums.size())
        {
            updateBitCounts(bitCounts, nums[windowEnd], 1);
            while (windowStart <= windowEnd && convertBitCountsToNumber(bitCounts) >= k)
            {
                minLength = min(minLength, windowEnd - windowStart + 1);
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }
            windowEnd++;
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};
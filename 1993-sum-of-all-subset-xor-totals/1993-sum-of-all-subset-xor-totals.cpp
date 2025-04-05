class Solution
{
private:
    void recur(int i, vector<int> &nums, int runningXOR, int &sum)
    {
        if(i == nums.size())
        {
            sum += runningXOR;
            return;
        }
        recur(i + 1, nums, runningXOR ^ nums[i], sum);
        recur(i + 1, nums, runningXOR, sum);
    }
public:
    int subsetXORSum(vector<int>& nums)
    {
        int sum = 0;
        recur(0, nums, 0, sum);
        return sum;
    }
};
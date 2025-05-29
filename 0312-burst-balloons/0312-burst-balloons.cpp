class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 1; i > 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                int maxi = 0;
                for(int k = i; k < j; k++)
                {
                    int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    maxi = max(steps, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 1];
    }
    int maxCoins(vector<int>& nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return matrixMultiplication(nums);
    }
};
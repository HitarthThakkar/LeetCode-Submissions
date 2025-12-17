class Solution
{
private:
    int recur(int i, int buyStatus, int buysLeft, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(i == prices.size()) return 0;

        if(dp[i][buyStatus][buysLeft] != -1) return dp[i][buyStatus][buysLeft];

        if(buyStatus == 1 && buysLeft == 0) return 0;

        if(buyStatus == 1)
        {
            int op1 = recur(i + 1, buyStatus, buysLeft, prices, dp);
            int op2 = recur(i + 1, 0, buysLeft - 1, prices, dp) - prices[i];
            return dp[i][buyStatus][buysLeft] = max(op1, op2);
        }
        else
        {
            int op1 = recur(i + 1, buyStatus, buysLeft, prices, dp);
            int op2 = recur(i + 1, 1, buysLeft, prices, dp) + prices[i];
            return dp[i][buyStatus][buysLeft] = max(op1, op2);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return recur(0, 1, k, prices, dp);
    }
};
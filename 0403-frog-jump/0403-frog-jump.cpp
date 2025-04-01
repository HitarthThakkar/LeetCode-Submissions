class Solution
{
private:
    bool recur(int ind, int k, vector<int> &stones, vector<vector<int>> &dp)
    {
        if(stones[ind] == stones.back()) return true;
        if(dp[ind][k] != -1) return dp[ind][k];
        for(int d = -1; d < 2; d++)
        {
            int curVal = stones[ind];
            int newVal = curVal + (k + d);
            auto it = lower_bound(stones.begin(), stones.end(), newVal);
            if(it != stones.end())
            {
                int newInd = it - stones.begin();
                if(stones[newInd] == newVal && newVal > curVal)
                    if(recur(newInd, k + d, stones, dp)) return dp[ind][k] = true;
            }
        }
        return dp[ind][k] = false;
    }
public:
    bool canCross(vector<int>& stones)
    {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return recur(0, 0, stones, dp);
    }
};
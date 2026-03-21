// oPtImIzEd CoDe

class Solution
{
public:

    int m = 1e9 + 7;

    int recur(int stepsLeft, int i, int maxPos, vector<vector<int>> &dp)
    {
        if(stepsLeft == 0) return (i == 0);
        if(i > stepsLeft) return 0;
        if(dp[stepsLeft][i] != -1) return dp[stepsLeft][i];
        int stay = 0, left = 0, right = 0;
        stay = recur(stepsLeft - 1, i, maxPos, dp);
        if(i > 0) left = recur(stepsLeft - 1, i - 1, maxPos, dp);
        if(i < maxPos) right = recur(stepsLeft - 1, i + 1, maxPos, dp);
        return dp[stepsLeft][i] = ((((stay + left) % m) + right) % m);
    }

    int numWays(int steps, int arrLen)
    {
        int maxPos = min(arrLen - 1, steps / 2);
        vector<vector<int>> dp(steps + 1, vector<int> (maxPos + 1, -1));
        return recur(steps, 0, maxPos, dp);
    }
};
class Solution
{
public:

    int dp[100][101][2];

    int recur(int i, int m, int t, vector<int> &pfx)
    {
        if(i >= pfx.size()) return 0;
        if(dp[i][m][t] != -1) return dp[i][m][t];
        // cout << i << " " << m << " " << t << endl;
        int mini = 1e9, mexi = -1e9;
        for(int x = 1; x <= (2 * m); x++)
        {
            if(i + x > pfx.size()) break;
            int sum = (t ? 0 : pfx[i + x - 1] - (i > 0 ? pfx[i - 1] : 0));
            int val = sum + recur(i + x, max(m, x), !t, pfx);
            mini = min(mini, val);
            mexi = max(mexi, val);
        }

        return dp[i][m][t] = (t ? mini : mexi);
    }

    int stoneGameII(vector<int>& piles)
    {
        vector<int> pfx = piles;
        for(int i = 1; i < piles.size(); i++) pfx[i] += pfx[i - 1];
        memset(dp, -1, sizeof(dp));
        return recur(0, 1, 0, pfx);
    }
};
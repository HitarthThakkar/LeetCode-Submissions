class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);
        dp[1] = true;

        vector<int> squareList;
        for(int i = 1; i < 317; i++) squareList.push_back(i * i);

        for(int i = 2; i <= n; i++)
        {
            for(auto e : squareList)
            {
                if(i - e < 0) break;
                if(!dp[i - e]) { dp[i] = true; break; }
            }
        }

        return dp[n];
    }
};
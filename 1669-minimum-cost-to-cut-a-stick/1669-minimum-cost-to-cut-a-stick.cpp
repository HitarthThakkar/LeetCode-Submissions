class Solution
{
public:
    int recur(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(i > j)
        {
            // cout <<  i << " " << j << " entered and returned 0." << endl;
            return 0;
        }
        else
        {
            // cout <<  i << " " << j << " entered ..." << endl;
            if(dp[i][j] != -1)
            {
                // cout << "   AND FOUND OUT VISITED !!! VALUE IS : " << dp[i][j] << endl;
                return dp[i][j];
            }
        }

        int mini = 1e9;
        int abhi_K_abhi = cuts[j + 1] - cuts[i - 1];

        // cout << "   Abhi K abhi " << abhi_K_abhi << " paisa nikal shane" << endl;

        for(int k = i; k <= j; k++)
        {
            int cost = abhi_K_abhi + recur(i, k - 1, cuts, dp) + recur(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        // cout << i << " " << j << " returned " << mini << endl;

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int nn = cuts.size();
        vector<vector<int>> dp(nn, vector<int> (nn, -1));
        return recur(1, nn - 2, cuts, dp);
    }
};
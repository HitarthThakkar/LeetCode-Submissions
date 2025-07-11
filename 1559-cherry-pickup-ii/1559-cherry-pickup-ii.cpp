#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>

class Solution
{
public:
    int recur(int i, int j1, int j2, int m, int n, vvi &grid, vvvi &dp)
    {
        if(i == m) return 0;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int current = 0;
        if(j1 == j2) current = grid[i][j1];
        else current = (grid[i][j1] + grid[i][j2]);

        int mex = 0;

        vi dj = {-1, 0, 1};
        int ni = i + 1;

        for(int ii = 0; ii < 3; ii++)
        {
            int nj1 = j1 + dj[ii];

            for(int jj = 0; jj < 3; jj++)
            {
                int nj2 = j2 + dj[jj];

                if(nj1 >= 0 && nj2 >= 0 && nj1 < n && nj2 < n)
                {
                    mex = max(mex, recur(ni, nj1, nj2, m, n, grid, dp));
                }
            }
        }

        return dp[i][j1][j2] = current + mex;
    }

    int cherryPickup(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vvvi dp(m, vvi(n, vi(n, -1)));
        return recur(0, 0, n - 1, m, n, grid, dp);
    }
};
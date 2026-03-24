class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        vector<vector<int>> res = grid;
        int sfxMul = 1;

        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                res[i][j] = (sfxMul % mod);
                sfxMul = (((grid[i][j] % mod) * sfxMul) % mod);
            }
        }

        int pfxMul = 1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[i][j] = (((res[i][j] % mod) * (pfxMul % mod)) % mod);
                pfxMul = (((grid[i][j] % mod) * pfxMul) % mod);
            }
        }

        return res;
    }
};
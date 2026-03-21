class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k)
    {
        int u = x;
        int d = x + k - 1;

        while(u < d)
        {
            for(int j = y; j < y + k; j++) swap(grid[u][j], grid[d][j]);
            u++, d--;
        }

        return grid;
    }
};
class Solution
{
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int x0 = m, x1 = 0;
        int y0 = n, y1 = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    x0 = min(x0, j);
                    x1 = max(x1, j);
                    y0 = min(y0, i);
                    y1 = max(y1, i);
                }
            }
        }

        return ((x1 - x0 + 1) * (y1 - y0 + 1));
    }
};
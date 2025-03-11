class Solution
{
private:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc] && grid[nr][nc])
            {
                dfs(nr, nc, vis, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++)
        {
            if(grid[i][0]) dfs(i, 0, vis, grid);
            if(grid[i][n - 1]) dfs(i, n - 1, vis, grid);
        }
        for(int j = 0; j < n; j++)
        {
            if(grid[0][j]) dfs(0, j, vis, grid);
            if(grid[m - 1][j]) dfs(m - 1, j, vis, grid);
        }

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};
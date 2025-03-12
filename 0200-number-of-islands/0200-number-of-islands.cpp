class Solution
{
private:
    bool isValid(int i, int j, vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '0');
    }
    void dfs(int r, int c, vector<vector<char>> &grid)
    {
        grid[r][c] = '0';
        vector<int> dr = {-1, 1, 0, 0}; vector<int> dc = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if(isValid(nr, nc, grid)) dfs(nr, nc, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid)
    {
        // 2025 Hiring Prep Sprint Q10 [Easy dfs / bfs]
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != '0')
                {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};
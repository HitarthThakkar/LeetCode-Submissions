class Solution
{
private:
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 0);
    }

    int dfs(int r, int c, vector<vector<int>> &grid)
    {
        int ans = grid[r][c];
        grid[r][c] = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(isValid(nr, nc, grid))
            {
                ans += dfs(nr, nc, grid);
            }
        }

        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int fishes = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    fishes = max(fishes, dfs(i, j, grid));
                }
            }
        }

        return fishes;
    }
};
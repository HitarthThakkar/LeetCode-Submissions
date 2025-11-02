class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards and walls
        for (auto& g : guards) grid[g[0]][g[1]] = 2;
        for (auto& w : walls) grid[w[0]][w[1]] = -1;
        
        // Process each direction separately
        // Right direction
        for (int i = 0; i < m; i++)
        {
            bool guarded = false;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded && grid[i][j] == 0) grid[i][j] = 1;
            }
        }
        
        // Left direction
        for (int i = 0; i < m; i++)
        {
            bool guarded = false;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 2) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded && grid[i][j] == 0) grid[i][j] = 1;
            }
        }
        
        // Down direction
        for (int j = 0; j < n; j++)
        {
            bool guarded = false;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 2) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded && grid[i][j] == 0) grid[i][j] = 1;
            }
        }
        
        // Up direction
        for (int j = 0; j < n; j++)
        {
            bool guarded = false;
            for (int i = m - 1; i >= 0; i--)
            {
                if (grid[i][j] == 2) guarded = true;
                else if (grid[i][j] == -1) guarded = false;
                else if (guarded && grid[i][j] == 0) grid[i][j] = 1;
            }
        }
        
        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) count++;
            }
        }

        return count;
    }
};
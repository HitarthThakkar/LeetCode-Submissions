class Solution
{
private:
    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    int dfs(int r, int c, vector<vector<int>> &grid, int color)
    {
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        grid[r][c] = color;
        int size = 1;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(isValid(nr, nc, grid.size(), grid[0].size()) && grid[nr][nc] == 1)
            {
                size += dfs(nr, nc, grid, color);
            }
        }

        return size;
    }
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colors = {0, 0};
        int maxSize = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    colors.push_back(dfs(i, j, grid, colors.size()));
                    maxSize = max(maxSize, colors.back());
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    int size = 1;
                    set<int> st;
                    for(int k = 0; k < 4; k++)
                    {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(isValid(nr, nc, m, n))
                        {
                            st.insert(grid[nr][nc]);
                        }
                    }
                    for(auto ele : st) size += colors[ele];
                    maxSize = max(size, maxSize);
                }
            }
        }
        return maxSize;
    }
};
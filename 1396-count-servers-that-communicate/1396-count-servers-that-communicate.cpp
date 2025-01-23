class Solution
{
public:
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> rc(m, 0), cc(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]) rc[i]++, cc[j]++;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] && (rc[i] > 1 || cc[j] > 1)) ans++;
        return ans;
    }
};
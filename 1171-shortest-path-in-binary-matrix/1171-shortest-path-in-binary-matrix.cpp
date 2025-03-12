class Solution
{
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist (m, vector<int> (n, 1e6));
        queue<pair<int, int>> q;
        if(grid[0][0] == 0) { q.push({0, 0}); dist[0][0] = 0; }
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            int dis = dist[r][c];
            q.pop();
            vector<int> dr = {-1, -1, -1, 1, 1, 1, 0, 0};
            vector<int> dc = {-1, 0, 1, -1, 0, 1, -1, 1};
            for(int i = 0; i < 8; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(isValid(nr, nc, m, n) && grid[nr][nc] == 0 && dist[nr][nc] > (dis + 1))
                {
                    dist[nr][nc] = dis + 1;
                    q.push({nr, nc});
                }
            }
        }
        return (dist[m - 1][n - 1] == 1e6 ? -1 : dist[m - 1][n - 1] + 1);
    }
};
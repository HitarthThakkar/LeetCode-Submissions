class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)q.push({i,j});
            }
        }

        int ans = 0;

        while(!q.empty())
        {
            int sz = q.size();
            bool change = false;

            while(sz--)
            {
                int x = q.front().first;
                int y=q.front().second;

                q.pop();

                vector<int> dx = {-1, 0, 0, 1};
                vector<int> dy = {0, -1, 1, 0};

                for(int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i];
                    int yy = y + dy[i];

                    if(xx >= 0 && yy >= 0 && xx < m && yy < n && grid[xx][yy] == 1)
                    {
                        change = true;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }

            if(change)
            {
                ans++;
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }

        return ans;

    }
};
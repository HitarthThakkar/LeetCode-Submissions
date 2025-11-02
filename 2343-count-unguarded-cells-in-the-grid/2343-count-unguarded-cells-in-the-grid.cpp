class Solution
{
public:

    void dfs(int sx, int sy, int m, int n, vector<vector<int>> &vis)
    {
        for(int i = sx + 1; i < m; i++)
        {
            if(vis[i][sy] == -1 || vis[i][sy] == 2) break;
            else vis[i][sy] = 1;
        }

        for(int i = sx - 1; i >= 0; i--)
        {
            if(vis[i][sy] == -1 || vis[i][sy] == 2) break;
            else vis[i][sy] = 1;
        }

        for(int j = sy - 1; j >= 0; j--)
        {
            if(vis[sx][j] == -1 || vis[sx][j] == 2) break;
            else vis[sx][j] = 1;
        }

        for(int j = sy + 1; j < n; j++)
        {
            if(vis[sx][j] == -1 || vis[sx][j] == 2) break;
            else vis[sx][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(auto e : guards) vis[e[0]][e[1]] = 2;
        for(auto e : walls) vis[e[0]][e[1]] = -1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 2)
                {
                    dfs(i, j, m, n, vis);
                }
            }
        }

        int unocc = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0)
                {
                    unocc++;
                }
            }
        }

        return unocc;
    }
};
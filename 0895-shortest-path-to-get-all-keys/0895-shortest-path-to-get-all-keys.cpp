#define vi vector<int>

class Solution
{
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int m = grid.size();
        int n = grid[0].length();
        set<vi> s;
        vector<vector<vector<int>>> vis(m, vector<vector<int>> (n, vector<int> (64, 1e9)));
        int count = 0; int sx, sy;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '.' || grid[i][j] == '#') continue;
                else if(grid[i][j] == '@') { sx = i; sy = j; }
                else count++;
            }
        }

        count /= 2;
        vis[sx][sy][0] = 0;

        s.insert({0, sx, sy, 0});

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!s.empty())
        {
            vi cur = *s.begin();
            s.erase(s.begin());

            int mtn = cur[0];
            int x = cur[1];
            int y = cur[2];
            int mask = cur[3];

            if(__builtin_popcount(mask) == count) return mtn;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#')
                {

                    if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f')
                    {
                        int dupmask = mask;
                        mask |= (1 << ((int) (grid[nx][ny] - 'a')));
                        if(vis[nx][ny][mask] > mtn + 1)
                        {
                            vis[nx][ny][mask] = mtn + 1;
                            s.insert({mtn + 1, nx, ny, mask});
                        }
                        mask = dupmask;
                    }
                    else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F')
                    {
                        int dupmask = mask;
                        int tbs = (1 << ((int) (grid[nx][ny] - 'A')));
                        if((mask & tbs) != 0)
                        {
                            if(vis[nx][ny][mask] > mtn + 1)
                            {
                                vis[nx][ny][mask] = mtn + 1;
                                s.insert({mtn + 1, nx, ny, mask});
                            }
                        }
                        mask = dupmask;
                    }
                    else
                    {
                        if(vis[nx][ny][mask] > mtn + 1)
                        {
                            vis[nx][ny][mask] = mtn + 1;
                            s.insert({mtn + 1, nx, ny, mask});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
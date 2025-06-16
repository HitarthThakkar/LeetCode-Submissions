#define vli vector<long long int>
class Solution
{
public:
    int minMoves(vector<string>& classroom, int energy)
    {
        int m = classroom.size();
        int n = classroom[0].length();

        // moves, x, y, energy left, mask of collected litters
        queue<vli> q;
        map<pair<int, int>, int> mp;

        int sx, sy, l_count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') { sx = i; sy = j; }
                else if(classroom[i][j] == 'L') { mp[{i, j}] = l_count;  l_count++; }
            }
        }

        if(l_count == 0) return 0;

        vector<vector<vector<long long>>> vis(m, vector<vector<long long>> (n, vector<long long> ((1 << l_count), -1)));

        q.push({0, sx, sy, energy, 0});
        vis[sx][sy][0] = energy;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty())
        {
            vli cur = q.front();
            q.pop();

            long long mtn = cur[0];
            long long x = cur[1];
            long long y = cur[2];
            long long el = cur[3];
            long long mask = cur[4];

            if(el == 0) continue;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X')
                {

                    if(classroom[nx][ny] == 'S' || classroom[nx][ny] == '.')
                    {
                        if(vis[nx][ny][mask] < el - 1)
                        {
                            vis[nx][ny][mask] = el - 1;
                            q.push({mtn + 1, nx, ny, el - 1, mask});
                        }
                    }
                    else if(classroom[nx][ny] == 'L')
                    {
                        int dupMask = mask;
                        dupMask |= (1 << mp[{nx, ny}]);

                        if(__builtin_popcount(dupMask) == l_count) return mtn + 1;

                        if(vis[nx][ny][dupMask] < el - 1)
                        {
                            vis[nx][ny][dupMask] = el - 1;
                            q.push({mtn + 1, nx, ny, el - 1, dupMask});
                        }
                    }
                    else if(classroom[nx][ny] == 'R')
                    {
                        if(vis[nx][ny][mask] < energy)
                        {
                            vis[nx][ny][mask] = energy;
                            q.push({mtn + 1, nx, ny, energy, mask});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
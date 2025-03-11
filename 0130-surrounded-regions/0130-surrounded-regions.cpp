class Solution
{
private:
    bool dfs(int r, int c, int m, int n, vector<vector<int>> &vis, vector<vector<char>> &board, vector<pair<int, int>> &list)
    {
        vis[r][c] = 1;
        list.push_back({r, c});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        bool tortn = true;
        if(r == 0 || c == 0 || r == m - 1 || c == n - 1) tortn = false;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O' && !vis[nr][nc])
            {
                if(tortn) tortn = dfs(nr, nc, m, n, vis, board, list);
                else dfs(nr, nc, m, n, vis, board, list);
            }
        }

        return tortn;
    }

public:
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    vector<pair<int, int>> list;

                    if(dfs(i, j, m, n, vis, board, list))
                    {
                        for(auto coord : list)
                        {
                            board[coord.first][coord.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
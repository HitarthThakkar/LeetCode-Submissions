class Solution
{
private:
    bool dfs(int r, int c, int m, int n, vector<vector<char>> &board, string &word, string &cur, vector<vector<bool>> &vis)
    {
        if(cur == word) { return true; }

        if(cur.length() >= word.length()) { return false; }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++)
        {
            bool flag = false;

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && word[cur.length()] == board[nr][nc])
            {
                cur += board[nr][nc];
                vis[nr][nc] = true;

                flag = dfs(nr, nc, m, n, board, word, cur, vis);
 
                vis[nr][nc] = false;
                cur.pop_back();
            }

            if(flag == true)
            {
                return true;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    string str = "";
                    str += word[0];

                    vis[i][j] = true;

                    if(dfs(i, j, m, n, board, word, str, vis))
                    {
                        return true;
                    }

                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};
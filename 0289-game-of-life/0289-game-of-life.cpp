class Solution
{
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size(); int n = board[0].size();
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};
        /*
            0 -> 0 to 0
            1 -> 1 to 1
            2 -> 0 to 1
            3 -> 1 to 0
        */
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int lc = 0;
                for(int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && (board[nr][nc] & 1)) lc++;
                    if(lc > 3) break;
                }
                if(board[r][c] & 1) { if(lc < 2 || lc > 3) board[r][c] = 3; }
                else if(lc == 3) board[r][c] = 2;
            }
        }
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(board[r][c] == 2) board[r][c] = 1;
                else if(board[r][c] == 3) board[r][c] = 0;
            }
        }
    }
};
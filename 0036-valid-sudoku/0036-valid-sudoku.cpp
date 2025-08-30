class Solution
{
public:
    bool rowValid(int r, int c, vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) if(i != c && board[r][i] == board[r][c]) return false;
        return true;
    }
    bool colValid(int r, int c, vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) if(i != r && board[i][c] == board[r][c]) return false;
        return true;
    }
    bool boxValid(int r, int c, vector<vector<char>> &board) {
        int spr = r - (r % 3);
        int spc = c - (c % 3);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int nr = spr + i;
                int nc = spc + j;
                if(nr == r && nc == c) continue;
                else if(board[r][c] == board[nr][nc]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    bool row = rowValid(i, j, board);
                    bool col = colValid(i, j, board);
                    bool box = boxValid(i, j, board);
                    if(!(row & col & box)) return false;
                }
            }
        }
        return true;
    }
};
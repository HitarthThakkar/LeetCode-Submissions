class Solution
{
public:
    void FastIO()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        FastIO();

        int m = board.size();
        int n = board[0].size();

        function<bool(int, int, int)> bt = [&](int i, int j, int k)
        {
            if (k == word.length()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;
            char temp = board[i][j];
            board[i][j] = '\0';
            if (bt(i + 1, j, k + 1) || bt(i - 1, j, k + 1)) return true;
            else if (bt(i, j + 1, k + 1) || bt(i, j - 1, k + 1)) return true;
            board[i][j] = temp;
            return false;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (bt(i, j, 0)) return true;

        return false;
    }
};
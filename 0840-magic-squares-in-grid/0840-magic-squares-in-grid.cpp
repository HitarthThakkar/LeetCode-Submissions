class Solution
{
public:
    bool isMagicSquare(int si, int sj, vector<vector<int>> &grid)
    {
        if(grid[si + 1][sj + 1] != 5) return false;
        if(grid[si][sj] & 1) return false;
        if(grid[si + 2][sj + 2] & 1) return false;
        if(grid[si + 2][sj] & 1) return false;
        if(grid[si][sj + 2] & 1) return false;

        set<int> s;

        // UNIQUE NUMBERS CHECK
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) s.insert(grid[si + i][sj + j]);
        if(s.size() != 9) return false;
        int i = 1;
        for(auto e : s) if(e != i) return false; else i++;

        s.clear();

        // ROW CHECK
        for(int i = 0; i < 3; i++) {
            int rowSum = 0;
            for(int j = 0; j < 3; j++) rowSum += grid[si + i][sj + j];
            s.insert(rowSum);
            if(s.size() > 1) return false;
        }

        // COL CHECK
        for(int i = 0; i < 3; i++) {
            int colSum = 0;
            for(int j = 0; j < 3; j++) colSum += grid[si + j][sj + i];
            s.insert(colSum);
            if(s.size() > 1) return false;
        }

        // DIAG CHECK
        int d1Sum = grid[si][sj] + grid[si + 1][sj + 1] + grid[si + 2][sj + 2];
        int d2Sum = grid[si][sj + 2] + grid[si + 1][sj + 1] + grid[si + 2][sj];

        return ((d1Sum == d2Sum) && (d1Sum == *s.begin()));
    }

    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;

        for(int i = 0; i < m - 2; i++)
        {
            for(int j = 0; j < n - 2; j++)
            {
                if(isMagicSquare(i, j, grid)) ct++;
            }
        }

        return ct;
    }
};
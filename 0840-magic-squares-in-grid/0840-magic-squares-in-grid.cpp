class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;

        for(int a = 0; a < m - 2; a++)
        {
            for(int b = 0; b < n - 2; b++)
            {
                int si = a;
                int sj = b;
                bool bad = false;

                if(grid[si + 1][sj + 1] != 5) continue;
                if(grid[si][sj] & 1) continue;
                if(grid[si + 2][sj + 2] & 1) continue;
                if(grid[si + 2][sj] & 1) continue;
                if(grid[si][sj + 2] & 1) continue;

                set<int> s;

                // UNIQUE NUMBERS CHECK
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        s.insert(grid[si + i][sj + j]);

                if(s.size() != 9) continue;

                int i = 1;
                for(auto e : s)
                {
                    if(e != i) { bad = true; break; }
                    else i++;
                }

                if(bad) continue;

                s.clear();

                // ROW CHECK
                for(int i = 0; i < 3; i++) {
                    int rowSum = 0;
                    for(int j = 0; j < 3; j++) rowSum += grid[si + i][sj + j];
                    s.insert(rowSum);
                    if(s.size() > 1) { bad = true; break; }
                }

                if(bad) continue;

                // COL CHECK
                for(int i = 0; i < 3; i++) {
                    int colSum = 0;
                    for(int j = 0; j < 3; j++) colSum += grid[si + j][sj + i];
                    s.insert(colSum);
                    if(s.size() > 1) { bad = true; break; }
                }

                if(bad) continue;

                // DIAG CHECK
                int d1Sum = grid[si][sj] + grid[si + 1][sj + 1] + grid[si + 2][sj + 2];
                int d2Sum = grid[si][sj + 2] + grid[si + 1][sj + 1] + grid[si + 2][sj];

                if((d1Sum == d2Sum) && (d1Sum == *s.begin())) ct++;
            }
        }

        return ct;
    }
};
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> v(100, vector<double> (100, 0));
        v[0][0] = (double) poured;

        for(int r = 0; r <= query_row; r++)
        {
            for(int c = 0; c <= r; c++)
            {
                if(v[r][c] > 1.00 && r != 99)
                {
                    v[r + 1][c] += (v[r][c] - 1.0) / 2.0;
                    v[r + 1][c + 1] += (v[r][c] - 1.0) / 2.0;
                }
            }
        }

        return min(1.0, v[query_row][query_glass]);
    }
};
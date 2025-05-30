class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> result;
        if(m == 1 || n == 1)
        {
            for(auto v: mat) for(auto e : v) result.push_back(e);
            return result;
        }

        int times = m + n - 2;

        int i1 = 0, j1 = 1;
        int i2 = 1, j2 = 0;
        bool dir = false;

        result.push_back(mat[0][0]);

        while(times--)
        {

            if(dir)
            {
                int jj = j2;
                for(int ii = i2; ii >= i1; ii--)
                {
                    result.push_back(mat[ii][jj]);
                    jj++;
                }
            }
            else
            {
                int jj = j1;
                for(int ii = i1; ii <= i2; ii++)
                {
                    result.push_back(mat[ii][jj]);
                    jj--;
                }
            }

            if(j1 == n - 1) i1++; else j1++;
            if(i2 == m - 1) j2++; else i2++;

            dir = !dir;
        }

        return result;
    }
};
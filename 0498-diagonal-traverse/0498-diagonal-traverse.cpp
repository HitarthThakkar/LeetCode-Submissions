class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> v;
        int i = 0, j = 0;
        bool flag = true;

        while(1)
        {
            if(i == m - 1 && j == n) return v;

            if(flag)
            {
                int ii = i, jj = j;

                while(ii > -1 && jj < n && ii < m && jj > -1) {
                    v.push_back(mat[ii][jj]);
                    ii--, jj++;
                }
            }
            else
            {
                int d1 = i;
                int d2 = n - j - 1;

                int ii = i - min(d1, d2), jj = j + min(d1, d2);

                while(ii < m && jj > -1 && jj < n && ii > -1) {
                    v.push_back(mat[ii][jj]);
                    ii++, jj--;
                }
            }

            if(i == m - 1) j++; else i++;
            flag = !flag;
        }

        return v;
    }
};
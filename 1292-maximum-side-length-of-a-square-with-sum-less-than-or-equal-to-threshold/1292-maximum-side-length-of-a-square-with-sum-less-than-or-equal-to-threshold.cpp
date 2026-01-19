class Solution
{
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold)
    {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mat[i][j] += mat[i - 1][j];
            }
        }

        int res = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int sl = max(1, res);

                while(i - sl + 1 >= 0 && j - sl + 1 >= 0)
                {
                    bool bad = false;
                    int sum = 0;

                    for(int jj = j; jj > j - sl; jj--)
                    {
                        sum += mat[i][jj];
                        if(i - sl >= 0)
                            sum -= mat[i - sl][jj];

                        if(sum > threshold)
                        {
                            bad = true;
                            break;
                        }
                    }

                    if(bad)
                        break;
                    else
                        res = max(res, sl);

                    sl++;
                }
            }
        }

        return res;
    }
};
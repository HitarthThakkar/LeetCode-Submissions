class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        long long posSum = 0;
        long long nonposSum = 0;
        int nonposCt = 0;
        int maxnonpos = -1e9;
        int minpos = 1e9;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] > 0)
                {
                    posSum += matrix[i][j];
                    minpos = min(minpos, matrix[i][j]);
                }
                else
                {
                    nonposSum += matrix[i][j];
                    nonposCt++;
                    maxnonpos = max(maxnonpos, matrix[i][j]);
                }
            }
        }

        posSum += (-1 * nonposSum);

        if(nonposCt & 1)
        {
            if((maxnonpos * -1) < minpos) posSum += (2 * maxnonpos);
            else posSum -= (2 * minpos);
        }

        return posSum;
    }
};
class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int i = 0, j = n - 1;

        while(1)
        {
            if(i >= n || j >= n) return grid;

            int ii = i, jj = j;
            vector<int> v;

            while(ii < n && jj < n)
            {
                v.push_back(grid[ii][jj]);
                ii++; jj++;
            }

            sort(v.begin(), v.end());

            if(j == 0)
            {
                reverse(v.begin(), v.end());

                int ii = i, jj = j, k = 0;

                while(ii < n && jj < n)
                {
                    grid[ii][jj] = v[k++];
                    ii++; jj++;
                }
            }
            else
            {
                int ii = i, jj = j, k = 0;

                while(ii < n && jj < n)
                {
                    grid[ii][jj] = v[k++];
                    ii++; jj++;
                }
            }

            if(j == 0) i++; else j--;
        }

        return grid;
    }
};
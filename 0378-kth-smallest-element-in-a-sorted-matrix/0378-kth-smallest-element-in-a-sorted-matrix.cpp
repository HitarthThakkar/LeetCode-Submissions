#define ll long long int
class Solution
{
public:
    int ctOfSmallerOrEqualToMid(long long mid, vector<vector<int>>& matrix)
    {
        int count = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            if(mid < matrix[i][0]) return count;
            int ct = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            count += ct;
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        // Many solutions for this problem exists.
        // #3 BS

        int m = matrix.size();
        int n = matrix[0].size();

        ll lo = matrix[0][0];
        ll hi = matrix[m - 1][n - 1];
        ll ans = hi;

        while(lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;

            if(ctOfSmallerOrEqualToMid(mid, matrix) >= k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
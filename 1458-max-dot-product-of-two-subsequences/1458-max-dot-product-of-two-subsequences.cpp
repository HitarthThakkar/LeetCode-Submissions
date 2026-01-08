class Solution
{
public:

    int recur(int i, int j, int s, int c, int &n, int &m, vector<int> &a, vector<int> &b, vector<vector<vector<vector<int>>>> &dp)
    {
        if(i == n && j == m)
        {
            if(!c) return -1e9;
            if(s == 0) return 0;
            else return -1e9;
        }

        if(i == n || j == m)
        {
            if(!c) return -1e9;
            if(s == 0) return 0;
            else return -1e9;
        }

        if(dp[i][j][s][c] != -1e9) return dp[i][j][s][c];

        int res;

        if(s == 0)
        {
            // take i & j
            int op1 = (a[i] * b[j]) + recur(i + 1, j + 1, 0, 1, n, m, a, b, dp);
            // take i only skip j
            int op2 = recur(i, j + 1, 1, c, n, m, a, b, dp);
            // take j only skip i
            int op3 = recur(i + 1, j, 2, c, n, m, a, b, dp);
            // skip both
            int op4 = recur(i + 1, j + 1, 0, c, n, m, a, b, dp);

            res = max({op1, op2, op3, op4});
        }
        else if(s == 1)
        {
            // take j with prechosen i
            int op1 = (a[i] * b[j]) + recur(i + 1, j + 1, 0, 1, n, m, a, b, dp);
            // skip j
            int op2 = recur(i, j + 1, 1, c, n, m, a, b, dp);

            res = max(op1, op2);
        }
        else if(s == 2)
        {
            // take i with prechosen j
            int op1 = (a[i] * b[j]) + recur(i + 1, j + 1, 0, 1, n, m, a, b, dp);
            // skip i
            int op2 = recur(i + 1, j, 2, c, n, m, a, b, dp);

            res = max(op1, op2);
        }

        return dp[i][j][s][c] = res;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (m, vector<vector<int>> (3, vector<int> (2, -1e9))));

        return recur(0, 0, 0, 0, n, m, nums1, nums2, dp);
    }
};
class Solution
{
public:
    int mod = 1e9 + 7;

    // I've read the whole editorial and also discussion and learning section.
    // Only after understanding why, what and how, I'm copying this code from
    // editorial approach 5. I've understood all 5 approaches.
    // I also know there's a 6th approach, better than this one.
    // That 6th one is left for future me.
    // If you're here again, understand all 6 and implement 6th one urself.
    // Wishing Good luck.
    
    int knightDialer(int n)
    {
        if (n == 1) return 10;

        vector<vector<long>> A =
        {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };

        vector<vector<long>> v =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

        n--;

        while (n > 0)
        {
            if ((n & 1) != 0)
            {
                v = multiply(v, A);
            }
            
            A = multiply(A, A);
            n >>= 1;
        }
        
        int ans = 0;
        for (long num : v[0])
        {
            ans = (ans + num) % mod;
        }
        
        return ans;
    }
    
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B)
    {
        vector<vector<long>> result(A.size(), vector<long>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B[0].size(); j++)
            {
                for (int k = 0; k < B.size(); k++)
                {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        
        return result;
    }
};
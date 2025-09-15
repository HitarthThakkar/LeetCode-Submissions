class Solution {
public:
    int maxXorSubsequences(vector<int>& nums)
    {
        // First thing to understand is that we just need to find a subsequence
        // from this array whose XOR is maximum.
        // No two subsequences and complex problem statement.

        // simply find a subset whose xor is maximum and return that maximum xor.

        // Code itself not too hard, concept is IMP.
        // Gaussian Elimination, XOR Basis
        // Same as we do in Gaussian Elimination to solve set of linear equations

        vector<int> basis(32, 0);

        for(auto x : nums)
        {
            if(x == 0) continue;    // MSB is not defined for 0.

            while(x != 0)
            {
                // Can do this MSB manually also, not too hard O(32) simple.
                int msbi = 31 - __builtin_clz(x);

                if(basis[msbi] == 0)
                {
                    basis[msbi] = x;
                    break;
                }
                else
                {
                    x ^= basis[msbi];
                }
            }
        }

        int mexXor = 0;

        for(int i = 31; i >= 0; i--)
        {
            if(mexXor < (mexXor ^ basis[i]))
            {
                mexXor ^= basis[i];
            }
        }

        return mexXor;
    }
};
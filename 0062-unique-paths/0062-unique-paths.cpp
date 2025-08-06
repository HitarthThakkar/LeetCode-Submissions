class Solution
{
public:
    int op_binomial_coefficient_calc(int m, int n)
    {
        if (n > m) swap(m, n);  // always choose the smaller for efficiency
        long long int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= (m + i);
            result /= i;
        }
        return result;
    }

    int uniquePaths(int m, int n)
    {
        // combinatorics problem, not DP. DP is for dumbos.
        // the func below calculates (m + n)! / (m! * n!) in efficient & smart manner using math.
        return op_binomial_coefficient_calc(n - 1, m - 1);
    }
};
class Solution
{
public:
    int integerReplacement(long long n)
    {
        if(n == 1) return 0;
        else if(__builtin_popcount(n) == 1) return log2(n);
        else if(n % 2 == 0) return (integerReplacement(n / 2) + 1);
        // else if(__builtin_popcount(n + 1) < __builtin_popcount(n - 1))
        //     return (integerReplacement(n + 1) + 1);
        else 
            return (min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1);
    }
};
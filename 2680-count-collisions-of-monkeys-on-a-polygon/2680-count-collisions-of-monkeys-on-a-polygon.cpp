class Solution
{
public:
    int powermod(long long x, long long y, long long p)
    {
        int res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0)
        {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    int monkeyMove(int n)
    {
        return (powermod(2, n, 1000000007) + 1000000007 - 2) % 1000000007;
    }
};
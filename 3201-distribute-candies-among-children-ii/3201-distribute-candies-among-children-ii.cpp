class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        int mini = max(0, (n - (2 * limit)));
        int mexi = min(n, limit);

        long long result = 0;

        for(int i = mini; i <= mexi; i++)
        {
            int nn = n - i;
            int mini2 = max(0, (nn - limit));
            int mexi2 = min(limit, nn);

            result += (mexi2 - mini2 + 1);
        }

        return result;
    }
};
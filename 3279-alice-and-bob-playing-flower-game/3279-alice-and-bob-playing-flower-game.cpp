class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long on = n / 2;
        long long en = n / 2;
        if(n & 1) on++;

        long long om = m / 2;
        long long em = m / 2;
        if(m & 1) om++;

        return ((on * em) + (om * en));
    }
};
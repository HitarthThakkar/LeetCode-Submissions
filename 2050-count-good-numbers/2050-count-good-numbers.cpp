class Solution
{
private:
    long long int powermod(long long int x, long long int y, long long int p)
    {
        int res = 1; x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1; x = (x * x) % p;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n)
    {
        long long int answer = 1, times = (n / 2), m = 1e9 + 7;
        answer = powermod(4, times, m) % m;
        if(n & 1) times++;
        answer = ((answer % m) * (powermod(5, times, m) % m)) % m;
        return answer;
    }
};
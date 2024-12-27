class Solution
{
public:
    int integerReplacement(long long n)
    {
        int ans = 0;
        while(n != 1)
        {
            if(n % 2 == 0) n /= 2;
            else if(n % 4 == 1 || n == 3) n--;
            else n++;
            ans++;
        }
        return ans;
    }
};
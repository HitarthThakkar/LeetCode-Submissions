class Solution
{
public:
    int countPrimes(int n)
    {
        if(n < 3) return 0;
        vector<int> v(n, 1);
        int ans = 0;
        for(int i = 2; i < n; i++)
        {
            if(v[i])
            {
                ans++;
                for(int k = i + i; k < n; k += i) v[k] = 0;
            }
        }
        return ans;
    }
};
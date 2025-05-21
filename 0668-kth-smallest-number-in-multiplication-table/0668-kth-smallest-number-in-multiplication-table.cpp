#define ll long long int
class Solution
{
public:
    bool enough(ll x, int m, int n, int k)
    {
        ll count = 0;
        for(int i = 1; i <= m; i++)
            count += min((x / i), 1LL * n);
        return (count >= k);
    }

    int findKthNumber(int m, int n, int k)
    {
        ll lo = 1;
        ll hi = m * n;
        ll ans = hi;

        while(lo <= hi)
        {
            ll mid = lo + ((hi - lo) / 2);

            if(enough(mid, m, n, k))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
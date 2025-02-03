class Solution
{
private:
    bool check(long long int k, int h, vector<int> &piles)
    {
        long long int time = 0;
        for(auto ele : piles)
            if(ele < k) { time++; }
            else { if(ele % k != 0) time++; time += (ele / k); }
        return (time <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        long long int lo = 1;
        long long int hi = *max_element(piles.begin(), piles.end());
        long long int ans = hi;
        while(hi - lo > 1)
        {
            long long int mid = lo + (hi - lo) / 2;
            if(check(mid, h, piles))
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if(check(lo, h, piles)) return lo;
        if(check(hi, h, piles)) return hi;
        return ans;
    }
};
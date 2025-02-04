class Solution
{
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int n = arr.size();
        int lo = 0; int hi = n - 1;
        int ans = 6696;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int missing = (arr[mid] - mid - 1);
            if(missing >= k) { ans = min(ans, mid); hi = mid - 1; }
            else { lo = mid + 1; }
        }
        if(ans == 6696) return arr[n - 1] + (k - (arr[n - 1] - n));
        int missing = (arr[ans] - ans - 1);
        return (arr[ans] - (missing - k) - 1);
    }
};
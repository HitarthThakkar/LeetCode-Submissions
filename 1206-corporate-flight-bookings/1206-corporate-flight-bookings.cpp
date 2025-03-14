class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> pfx(n, 0);
        for(auto booking : bookings)
        {
            pfx[booking[0] - 1] += booking[2];
            if(booking[1] < n) pfx[booking[1]] -= booking[2];
        }
        for(int i = 1; i < n; i++) pfx[i] += pfx[i - 1];
        return pfx;
    }
};
class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<int> pfx(1001, 0);
        for(auto v : trips)
        {
            pfx[v[1]] += v[0];
            pfx[v[2]] -= v[0];
        }
        for(int i = 1; i < 1001; i++) pfx[i] += pfx[i - 1];
        for(auto e : pfx) if(e > capacity) return false;
        return true;
    }
};
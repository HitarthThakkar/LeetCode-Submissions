class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int mex = -1;
        for(auto v : trips) mex = max(mex, v[2]);
        vector<int> pfx(mex + 1, 0);
        for(auto v : trips)
        {
            pfx[v[1]] += v[0];
            pfx[v[2]] -= v[0];
        }
        for(int i = 1; i < pfx.size(); i++) pfx[i] += pfx[i - 1];
        for(auto e : pfx) if(e > capacity) return false;
        return true;
    }
};
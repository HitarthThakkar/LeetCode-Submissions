class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();
        vector<int> pfx;
        pfx.push_back(0);
        for(auto ch : blocks)
            if(ch == 'W') pfx.push_back(pfx.back() + 1);
            else pfx.push_back(pfx.back());
        int res = n;
        for(int i = k; i < pfx.size(); i++)
            res = min(res, pfx[i] - pfx[i - k]);
        return res;
    }
};
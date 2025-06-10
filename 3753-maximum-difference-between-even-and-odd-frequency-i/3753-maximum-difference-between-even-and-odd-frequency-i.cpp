class Solution
{
public:
    int maxDifference(string s)
    {
        unordered_map<char,int> mp;
        for(auto ele : s) mp[ele]++;
        int mxo = 0, mie = 10000;
        for(auto ele : mp)
        {
            int f = ele.second;
            if(f & 1) mxo = max(mxo, f);
            else mie = min(mie, f);
        }
        return (mxo - mie);
    }
};
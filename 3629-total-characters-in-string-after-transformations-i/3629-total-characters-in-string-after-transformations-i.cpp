class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        int ans = s.length();
        map<int, int> mp;
        for(auto ele : s) mp[(int)('z' - ele) + 1]++;
        while(t >= mp.begin()->first)
        {
            int one = mp.begin()->first;
            int two = mp.begin()->second;
            mp.erase(mp.begin());
            ans %= 1000000007; two %= 1000000007;
            ans += two; ans %= 1000000007;
            mp[one + 26] += two;
            mp[one + 25] += two;
        }
        return ans;
    }
};
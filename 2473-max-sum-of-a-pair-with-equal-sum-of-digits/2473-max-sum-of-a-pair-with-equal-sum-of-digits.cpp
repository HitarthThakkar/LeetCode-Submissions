class Solution
{
public:
    int sods(int n) { int ans = 0; while(n) { ans += (n % 10); n/= 10; } return ans; }
    int maximumSum(vector<int>& nums)
    {
        map<int, int> mp;
        int ans = -1;
        for(auto ele : nums)
        {
            int sod = sods(ele);
            if(mp.find(sod) != mp.end())
            {
                ans = max(ans, mp[sod] + ele);
                mp[sod] = max(mp[sod], ele);
            }
            else
            {
                mp[sod] = ele;
            }
        }
        return ans;
    }
};
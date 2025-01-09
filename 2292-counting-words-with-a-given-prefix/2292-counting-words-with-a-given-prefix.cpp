class Solution
{
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int ans = 0, n = pref.length();
        for(auto ele : words) if(ele.length() >= n && ele.substr(0, n) == pref) ans++;
        return ans;
    }
};
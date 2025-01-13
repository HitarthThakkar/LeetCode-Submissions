class Solution
{
public:
    int minimumLength(string s)
    {
        int ans = 0;
        vector<int> freq(26, 0);
        for(auto ele : s) freq[ele - 'a']++;
        for(auto ele : freq)
        {
            if(ele & 1) ans++;
            else if(ele > 0) ans += 2;
        }
        return ans;
    }
};
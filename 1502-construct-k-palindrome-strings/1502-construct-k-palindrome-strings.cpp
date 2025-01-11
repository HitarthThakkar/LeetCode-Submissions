class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if(s.length() < k) return false;
        vector<int> freq(26, 0);
        for(auto ele : s) freq[ele - 'a']++;
        for(auto ele : freq) if(ele & 1) k--;
        return (k >= 0);
    }
};
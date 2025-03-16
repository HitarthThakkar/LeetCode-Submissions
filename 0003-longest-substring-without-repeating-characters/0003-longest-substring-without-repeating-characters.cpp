class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int mexlen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> m;
        while(r < s.length())
        {
            if(m.find(s[r]) == m.end())
            {
                m.insert(std::pair<char,int>(s[r], r));
                mexlen = max(mexlen, r - l + 1);
            }
            else
            {
                auto it = m.find(s[r]);
                if(it->second < l)
                {
                    it->second = r;
                    mexlen = max(mexlen, r - l + 1);
                }
                else
                {
                    l = (it->second + 1);
                    it->second = r;
                }
                mexlen = max(mexlen, r - l + 1);
            }
            r++;
        }
        return mexlen;
    }
};
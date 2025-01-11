class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.length(), j = 0;
        vector<int> lps(n, 0);
        for(int i = 1; i < needle.length(); i++)
        {
            while(j > 0 && needle[j] != needle[i]) j = lps[j - 1];
            if(needle[j] == needle[i]) lps[i] = ++j;
        }
        j = 0;
        for(int i = 0; i < haystack.length(); i++)
        {
            if(haystack[i] == needle[j]) { j++; if(j == n) return i - n + 1;}
            else{ while(j > 0 && needle[j] != haystack[i]) j = lps[j - 1];
            if(needle[j] == haystack[i]) j++;
        }}
        return -1;
    }
};
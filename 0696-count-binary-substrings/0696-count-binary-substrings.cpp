class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int pct = 0;
        int ct = 0;
        int res = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(i == 0 || s[i] != s[i - 1]) res += min(pct, ct), pct = ct, ct = 1;
            else ct++;
        }

        res += min(pct, ct);
        return res;
    }
};
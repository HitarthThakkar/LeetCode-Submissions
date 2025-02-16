class Solution
{
public:
    bool hasSpecialSubstring(string s, int k)
    {
        for(int sp = 0; sp <= s.length() - k; sp++)
        {
            bool flag = true;
            char ch = s[sp];
            int lp = sp + k;
            for(int i = sp + 1; i < lp; i++) if(s[i] != ch) { flag = false; break; }
            if(flag)
            {
                if(sp - 1 >= 0 && s[sp - 1] == ch) continue;
                if(lp < s.length() && s[lp] == ch) continue;
                else return true;
            }
        }
        return false;
    }
};
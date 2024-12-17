class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int sp = 0, lp = s.size() - 1;
        while(sp < lp) swap(s[sp], s[lp]), sp++, lp--;
    }
};
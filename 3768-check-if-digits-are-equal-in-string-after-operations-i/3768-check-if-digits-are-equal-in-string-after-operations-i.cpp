class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while(s.length() != 2)
        {
            for(int i = 0; i < s.length() - 1; i++)
            {
                s[i] = (char) (((int)s[i] + (int)s[i+1]) % 10);
            }
            s.pop_back();
        }
        return (s[0] == s[1]);
    }
};
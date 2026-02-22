class Solution
{
public:
    string maximumXor(string s, string t)
    {
        int z = 0;
        int o = 0;

        for(auto c : t)
        {
            if(c == '0') z++;
            else o++;
        }

        string res = "";

        for(auto c : s)
        {
            if(c == '0')
            {
                if(o) {
                    o--;
                    res += '1';
                }
                else {
                    res += '0';
                }
            }
            else
            {
                if(z) {
                    z--;
                    res += '1';
                }
                else {
                    res += '0';
                }
            }
        }

        return res;
    }
};
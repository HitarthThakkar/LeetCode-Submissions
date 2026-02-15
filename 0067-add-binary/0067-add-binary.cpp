class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(a.length() < b.length()) a += '0';
        while(b.length() < a.length()) b += '0';

        string res = "";
        char carry = '0';

        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == '1' && b[i] == '1')
            {
                if(carry == '1') res += '1';
                else res += '0', carry = '1';
            }
            else if(a[i] == '0' && b[i] == '0')
            {
                if(carry == '1') res += '1', carry = '0';
                else res += '0';
            }
            else
            {
                if(carry == '1') res += '0';
                else res += '1';
            }
        }

        if(carry == '1') res += '1';

        reverse(res.begin(), res.end());

        return res;
    }
};
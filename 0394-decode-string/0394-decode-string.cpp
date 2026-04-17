class Solution
{
public:

    string recur(int l, int r, string &s)
    {
        if(l > r) return "";
        string res = "";

        for(int i = l; i <= r; i++)
        {
            if(s[i] >= '1' && s[i] <= '9')
            {
                int broi, brci, times = 0;
                for(int j = i; j <= r; j++)
                {
                    if(s[j] == '[') { broi = j; break; }
                    times = (times * 10) + (int) s[j] - '0';
                }
                int balance = 1;
                for(int k = broi + 1; k <= r; k++)
                {
                    if(s[k] == '[') balance++;
                    else if(s[k] == ']') balance--;
                    if(balance == 0) { brci = k; break; }
                }
                i = brci;
                string toAdd = recur(broi + 1, brci - 1, s);
                while(times--) res += toAdd;
            }
            else
            {
                res += s[i];
            }
        }

        return res;
    }

    string decodeString(string s)
    {
        return recur(0, s.length() - 1, s);
    }
};
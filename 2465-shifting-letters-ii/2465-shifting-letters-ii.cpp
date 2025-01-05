class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts)
    {
        int n = s.length();
        vector<int> pfx(n + 1, 0);

        for(auto vec : shifts)
        {
            if(vec[2]) pfx[vec[0]]++, pfx[vec[1] + 1]--;
            else pfx[vec[0]]--, pfx[vec[1] + 1]++;
        }

        pfx[0] %= 26;
        for(int i = 1; i <= n; i++) pfx[i] += pfx[i - 1], pfx[i] %= 26;

        for(int i = 0; i < n; i++)
        {
            int sint = (int)s[i];
            char ch = (char)((int)s[i] + pfx[i]);

            if('a' <= ch && ch <= 'z')
            {
                s[i] = ch;
            }
            else if(pfx[i] > 0)
            {
                pfx[i] -= (122 - sint + 1);
                s[i] = (char)(97 + pfx[i]);
            }
            else
            {
                pfx[i] += (sint - 97 + 1);
                s[i] = (char)(122 + pfx[i]);
            }
        }

        return s;
    }
};
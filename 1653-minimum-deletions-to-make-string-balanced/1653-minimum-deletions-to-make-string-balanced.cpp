class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.length();
        int res = 1e9;

        vector<int> sfx(n, 0);  // suffix 'a' count

        for(int i = n - 1; i >= 0; i--)
        {
            sfx[i] = (s[i] == 'a');
            sfx[i] += (i < n - 1 ? sfx[i + 1] : 0);
        }

        if(sfx[0] == n) return 0;   // all 'a'

        int pbc = 0;    // previous 'b' count

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
            {
                res = min(res, pbc + sfx[i]);
                pbc++;
            }
        }

        res = min(res, pbc);

        return res;
    }
};
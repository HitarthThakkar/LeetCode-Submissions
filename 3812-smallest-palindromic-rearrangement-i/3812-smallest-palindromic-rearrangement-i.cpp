class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.length();
        vector<int> v(26, 0);
        for(auto c : s) v[c - 'a']++;
        if(n & 1)
        {
            string ans = "";
            char cc;
            for(int i = 0; i < 26; i++)
            {
                if(v[i] & 1) cc = ('a' + i);
                int times = v[i] / 2;
                while(times--) ans += ('a' + i);
            }
            string rev = ans;
            reverse(rev.begin(), rev.end());
            ans += cc;
            ans += rev;
            return ans;
        }
        else
        {
            string ans = "";
            for(int i = 0; i < 26; i++)
            {
                int times = v[i] / 2;
                while(times--) ans += ('a' + i);
            }
            string rev = ans;
            reverse(rev.begin(), rev.end());
            ans += rev;
            return ans;
        }
    }
};
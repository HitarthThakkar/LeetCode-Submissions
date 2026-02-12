class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            if(n - i < res) break;
            map<char, int> m;

            for(int j = i; j < n; j++)
            {
                m[s[j]]++;

                set<int> s;
                for(auto e : m) { if(s.size() > 1) break; s.insert(e.second); }
                if(s.size() == 1) res = max(res, j - i + 1);
            }
        }

        return res;
    }
};
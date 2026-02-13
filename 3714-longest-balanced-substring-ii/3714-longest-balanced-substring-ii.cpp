class Solution
{
public:

    int triple(string &s)
    {
        map<vector<int>, int> m;
        m.insert({{0, 0, 0}, -1});
        vector<int> f(3, 0);
        int res = 0;

        for(int i = 0; i < s.length(); i++)
        {
            f[s[i] - 'a']++;

            vector<int> dif = {f[0] - f[1], f[0] - f[2], f[1] - f[2]};

            if(m.find(dif) != m.end()) res = max(res, i - m[dif]);
            else m.insert({dif, i});
        }

        return res;
    }

    int singleContinuous(string &s)
    {
        int res = 0;

        int single_conti_count = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(i == 0 || s[i - 1] != s[i]) single_conti_count = 1;
            else single_conti_count++;
            res = max(res, single_conti_count);
        }

        return res;
    }

    int double_with_undesired(char one, char two, char undesired, string &s)
    {
        map<int, int> m;
        m.insert({0, -1});
        int res = 0;

        int oneCount = 0, twoCount = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == undesired)
            {
                m.clear();
                oneCount = 0, twoCount = 0;
                m.insert({0, i});
            }
            else
            {
                if(s[i] == one) oneCount++;
                else twoCount++;

                int dif = oneCount - twoCount;

                if(m.find(dif) != m.end()) res = max(res, i - m[dif]);
                else m.insert({dif, i});
            }
        }

        return res;
    }

    int longestBalanced(string s)
    {
        // total 8 cases - a, b, c, ab, ac, bc, abc

        return max({
            singleContinuous(s),
            double_with_undesired('a', 'b', 'c', s),
            double_with_undesired('a', 'c', 'b', s),
            double_with_undesired('b', 'c', 'a', s),
            triple(s)
        });
    }
};
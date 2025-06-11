class Solution
{
public:
    vector<string> result;

    void recur(string s, int target, int i, const string &path, long eval, long residual)
    {
        if(i == s.length())
        {
            if(eval == target) result.push_back(path);
            return;
        }

        string curStr;
        long num = 0;

        // Backtracking loop concept [@codeconceptswithanimeshyt]
        for(int j = i; j < s.length(); j++)
        {
            // handling '05' or '08' type leading zeroes cases
            if(j > i && s[i] == '0') return;

            curStr += s[j];
            num = (num * 10) + s[j] - '0';

            if(i == 0)
            {
                recur(s, target, j + 1, path + curStr, num, num);
            }
            else
            {
                recur(s, target, j + 1, path + "+" + curStr, eval + num, num);
                recur(s, target, j + 1, path + "-" + curStr, eval - num, -num);
                recur(s, target, j + 1, path + "*" + curStr, eval - residual + residual * num, residual * num);
            }
        }
    }
    vector<string> addOperators(string num, int target)
    {
        recur(num, target, 0, "", 0, 0);
        return result;
    }
};
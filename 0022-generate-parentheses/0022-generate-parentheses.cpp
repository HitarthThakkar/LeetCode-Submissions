class Solution
{
private:
    void recur(string cur, vector<string> &ans, int ll, int rl)
    {
        if(ll == 0 && rl == 0)
        {
            ans.push_back(cur);
            return;
        }
        if(ll == rl)
        {
            cur += '(';
            recur(cur, ans, ll - 1, rl);
        }
        else if(ll < rl)
        {
            if(ll > 0)
            {
                cur.push_back('(');
                recur(cur, ans, ll - 1, rl);
                cur.pop_back();
                cur.push_back(')');
                recur(cur, ans, ll, rl - 1);
            }
            else
            {
                cur.push_back(')');
                recur(cur, ans, ll, rl - 1);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> answer;
        recur("", answer, n, n);
        return answer;
    }
};
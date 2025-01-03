class Solution
{
public:
    int maxDepth(string s)
    {
        int ct = 0, ans = 0;
        for(auto ele : s)
        {
            if(ele == '(') ct++, ans = max(ans, ct);
            else if(ele == ')') ct--;
        }
        return ans;
    }
};
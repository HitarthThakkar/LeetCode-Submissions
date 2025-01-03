class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = ""; int deepness = 0;
        for(auto ele : s)
        {
            bool flag = (deepness == 0 && ele == '(') || (deepness == 1 && ele == ')');
            if(!flag) result += ele;
            if(ele == '(') deepness++; else deepness--;
        }
        return result;
    }
};
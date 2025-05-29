class Solution
{
public:
    int calculate(int prev, int cur, char op)
    {
        int newPrevValue;
        if(op == '+') newPrevValue = prev + cur;
        else if(op == '-') newPrevValue = prev - cur;
        else if(op == '*') newPrevValue = prev * cur;
        else newPrevValue = prev / cur;
        return newPrevValue;
    }
    int calculate(string s)
    {
        // used the idea that (0 + s == s).
        int n = s.length();
        int prev = 0;
        int cur = 0;
        int result = 0;
        char op = '+';

        for(int i = 0; i < n; i++)
        {
            if(std::isdigit(s[i]))
            {
                cur = (cur * 10) + (s[i] - '0');
            }
            else if(s[i] != ' ')
            {
                int intermediate = calculate(prev, cur, op);

                if(s[i] == '+' || s[i] == '-')
                {
                    result += intermediate;
                    prev = 0;
                }
                else
                {
                    prev = intermediate;
                }

                op = s[i];
                cur = 0;
            }
        }

        int intermediate = calculate(prev, cur, op);

        return (result + intermediate);
    }
};
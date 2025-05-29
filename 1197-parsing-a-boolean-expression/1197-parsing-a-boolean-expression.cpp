class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> s;
        s.push('t');
        s.push('&');
        for(auto c : expression)
        {
            if(c == ',') continue;
            else s.push(c);

            int t = 0;
            int f = 0;
            if(s.top() == ')')
            {
                while(s.top() != '(')
                {
                    if(s.top() == 't') t++;
                    else if(s.top() == 'f') f++;
                    s.pop();
                }
                s.pop();
                char op = s.top();
                s.pop();
                if(op == '!')
                {
                    if(t > 0) s.push('f');
                    else s.push('t');
                }
                else if(op == '&')
                {
                    if(f > 0) s.push('f');
                    else s.push('t');
                }
                else if(op == '|')
                {
                    if(t > 0) s.push('t');
                    else s.push('f');
                }
            }
        }

        while(s.size() > 1)
        {
            char a = s.top();
            s.pop();
            char op = s.top();
            s.pop();

            if(op == '!')
            {
                s.push((a == 't' ? 'f' : 't'));
            }
            else
            {
                char b = s.top();
                s.pop();

                if(op == '&')
                {
                    if(a == b && a =='t') s.push('t');
                    else s.push('f');
                }
                else if(op == '|')
                {
                    if(a == 't' || b == 't') s.push('t');
                    else s.push('f');
                }
            }
        }

        return (s.top() == 't' ? true : false);
    }
};
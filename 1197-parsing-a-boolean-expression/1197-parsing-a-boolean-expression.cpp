class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;

        for (char c : expression)
        {
            if (c == ',' || c == '(') continue;

            if (c == ')')
            {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|')
                {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                char op = st.top();
                st.pop();

                if (op == '!') st.push(hasTrue ? 'f' : 't');
                else if (op == '&') st.push(hasFalse ? 'f' : 't');
                else st.push(hasTrue ? 't' : 'f');
            }
            else
            {
                st.push(c);
            }
        }

        return (st.top() == 't');
    }
};
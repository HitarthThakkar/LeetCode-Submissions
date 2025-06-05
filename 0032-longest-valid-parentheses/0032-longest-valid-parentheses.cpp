class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            if(c == '(') st.push(i);
            else {
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }

        if(st.empty()) return n;

        int answer = 0;

        int right = n;

        while(!st.empty())
        {
            // cout << right << " " << st.top() << endl;
            answer = max(answer, right - st.top() - 1);
            right = st.top();
            st.pop();
        }

        answer = max(answer, right);

        return answer;
    }
};
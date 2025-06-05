class Solution
{
public:
    int longestValidParentheses(string s)
    {
        // Somewhat advanced solution, Requires dry run, copied but OPed. 
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else answer = max(answer, i - st.top());
            }
        }
        return answer;
    }
};
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string answer = "";
        stack<int> st;
        for(int i = 0; i < pattern.length() + 1; i++)
        {
            st.push(i + 1);
            if(i >= pattern.length() || pattern[i] == 'I')
            {
                while(!st.empty())
                {
                    answer += to_string(st.top());
                    st.pop();
                }
            }
        }
        return answer;
    }
};
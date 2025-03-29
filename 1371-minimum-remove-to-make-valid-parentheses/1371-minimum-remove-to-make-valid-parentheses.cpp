class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        // 2025 Hiring Prep Sprint Week_2 Q5
        stack<pair<char,int>> st; int i = 0; string ans;
        for(auto ele : s)
        {
            if(ele != '(' && ele != ')') {i++; continue;}
            if(!st.empty() && st.top().first == '(' && ele == ')') st.pop();
            else st.push({ele, i}); i++;
        }
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(!st.empty() && st.top().second == i) st.pop();
            else ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end()); return ans;
    }
};
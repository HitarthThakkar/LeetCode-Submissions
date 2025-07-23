class Solution
{
private:
    string removeSubstring(string &input, string &target)
    {
        stack<char> st;
        for (char ch : input)
            if (ch == target[1] && !st.empty() && st.top() == target[0]) st.pop();
            else st.push(ch);
        string output;
        while (!st.empty())
        {
            output += st.top();
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;
        string first, second;
        if(x > y) first = "ab", second = "ba";
        else first = "ba", second = "ab";
        string s_v1 = removeSubstring(s, first);
        int ctPair = (s.length() - s_v1.length()) / 2;
        ans += ctPair * max(x, y);
        string s_v2 = removeSubstring(s_v1, second);
        ctPair = (s_v1.length() - s_v2.length()) / 2;
        ans += ctPair * min(x, y);
        return ans;
    }
};
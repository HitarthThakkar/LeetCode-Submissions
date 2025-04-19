class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int answer = 0;

        for(int i = 0; i < n; i++)
        {
            int l = pse[i] + 1;
            int r = nse[i] - 1;
            answer = max(answer, ((r - l + 1) * heights[i]));
        }

        return answer;
    }
};
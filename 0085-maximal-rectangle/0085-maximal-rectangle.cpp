class Solution
{
public:

    int largestRectangleInHistogram(vector<int> &histo)
    {
        int n = histo.size();

        vector<int> nse(n, n);
        vector<int> pse(n, -1);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && histo[st.top()] >= histo[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && histo[st.top()] >= histo[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        int res = 0;

        for(int i = 0; i < n; i++)
        {
            int length = nse[i] - pse[i] - 1;
            int cur = histo[i] * (length);
            res = max(res, cur);
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> histo(n, 0);
        int res = 0;

        for(int level = 0; level < m; level++)
        {
            for(int i = 0; i < n; i++)
            {
                if(matrix[level][i] == '0') histo[i] = 0;
                else histo[i]++;
            }

            res = max(res, largestRectangleInHistogram(histo));
        }

        return res;
    }
};
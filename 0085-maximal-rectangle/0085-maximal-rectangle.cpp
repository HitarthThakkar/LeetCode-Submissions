class Solution
{
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> mat(m, vector<int> (n));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }

        int answer = 0;

        for(int i = 0; i < m; i++)
        {
            vector<int> ground;
            for(int j = 0; j < n; j++)
            {
                if(i > 0 && mat[i][j] != 0) mat[i][j] += mat[i - 1][j];
                ground.push_back(mat[i][j]);
            }
            answer = max(answer, largestRectangleArea(ground));
        }

        return answer;
    }
};
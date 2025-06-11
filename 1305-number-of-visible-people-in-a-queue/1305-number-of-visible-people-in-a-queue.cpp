class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int>& heights)
    {
        int n = heights.size();

        stack<int> st;
        vector<int> nge(n, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            int tbr = 0;

            while(!st.empty())
            {
                if(heights[i] >= heights[st.top()])
                {
                    tbr++;
                    st.pop();
                }
                else
                {
                    break;
                }
            }

            if(!st.empty())
            {
                nge[i] = tbr + 1;
            }
            else
            {
                nge[i] = tbr;
            }

            st.push(i);
        }

        return nge;
    }
};
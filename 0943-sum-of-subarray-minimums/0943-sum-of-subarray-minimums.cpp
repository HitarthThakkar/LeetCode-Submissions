class Solution
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        int m = 1000000007;
        vector<int> pseq(n, -1), nse(n, n); // NOT nseq and nse. {OP} [See WA submission before]
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                pseq[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long answer = 0;

        for(int i = 0; i < n; i++)
        {
            int l = pseq[i] + 1;
            int r = nse[i] - 1;

            int left = i - l;
            int right = r - i;

            left %= m;
            right %= m;

            int contribution = 0;

            if(left >= 0 && right >= 0)
            {
                contribution++;
                contribution += left;
                contribution += right;
                contribution += (left * right);
            }
            
            contribution %= m;
            arr[i] %= m;

            answer += (1LL * contribution * arr[i]);

            answer %= m;
        }

        return answer;
    }
};
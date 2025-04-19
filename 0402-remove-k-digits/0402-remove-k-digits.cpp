class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        string answer = "";
        vector<int> NSE(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && num[st.top()] > num[i])
            {
                NSE[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            if(NSE[i] - i <= k)
            {
                k -= (NSE[i] - i);
                i = NSE[i] - 1;
            }
            else
            {
                answer += num[i];
            }
        }

        reverse(answer.begin(), answer.end());
        while(answer.length() > 0 && answer.back() == '0') answer.pop_back();
        reverse(answer.begin(), answer.end());

        return (answer == "" ? "0" : answer);
    }
};
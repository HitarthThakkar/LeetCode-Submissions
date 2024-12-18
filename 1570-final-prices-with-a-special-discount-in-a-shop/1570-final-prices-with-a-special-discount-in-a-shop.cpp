class Solution
{
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        stack<pair<int, int>> st; int n = prices.size();
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top().first >= prices[i])
                prices[st.top().second] -= prices[i], st.pop();
            st.push({prices[i], i});
        }
        return prices;
    }
};
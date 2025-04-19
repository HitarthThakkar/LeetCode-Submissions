class StockSpanner
{
public:
    int i = 1;
    stack<pair<int, int>> st;
    StockSpanner() {}
    int next(int price)
    {
        while(!st.empty() && st.top().first <= price) st.pop();
        int answer;
        if(st.empty()) answer = i;
        else answer = (i - st.top().second);
        st.push({price, i++});
        return answer;
    }
};
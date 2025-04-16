class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int answer = 0;
        for(int i = 0; i < n - 1; i++)
            if(prices[i + 1] > prices[i])
                answer += prices[i + 1] - prices[i];
        return answer;
    }
};
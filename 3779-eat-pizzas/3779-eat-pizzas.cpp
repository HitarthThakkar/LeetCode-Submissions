class Solution
{
public:
    long long maxWeight(vector<int>& pizzas)
    {
        sort(pizzas.begin(), pizzas.end());
        // for(auto ele : pizzas) cout << ele << " ";
        int days = (pizzas.size() / 4);
        int odd_days = days / 2; if(days & 1) odd_days++;
        int even_days = days / 2;
        long long int ans = 0;
        while(odd_days--)
            { ans += pizzas.back(); pizzas.pop_back(); }
        while(even_days--)
            { pizzas.pop_back(); ans += pizzas.back(); pizzas.pop_back(); }
        return ans;
    }
};
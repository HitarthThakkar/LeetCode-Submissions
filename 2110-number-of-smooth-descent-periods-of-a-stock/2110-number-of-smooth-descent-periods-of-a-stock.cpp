class Solution
{
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        long long int streak = 0, res = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            if(i == 0 || prices[i - 1] - 1 == prices[i])
            {
                streak++;
            }
            else
            {
                long long int toAdd = (streak) * (streak + 1) / 2;
                res += toAdd;
                streak = 1;
            }
        }

        long long int toAdd = (streak) * (streak + 1) / 2;
        res += toAdd;

        return res;
    }
};
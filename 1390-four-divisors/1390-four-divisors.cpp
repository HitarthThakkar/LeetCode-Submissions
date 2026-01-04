class Solution
{
public:
    int sumFourDivisors(vector<int>& nums)
    {
        int res = 0;
        unordered_map<int, int> dp;

        for(auto e : nums)
        {

            if(dp.find(e) != dp.end())
            {
                res += dp[e];
            }
            else
            {
                int divCount = 0;
                int sumForThisE = 0;
                bool bad = false;

                for(int i = 1; i <= sqrt(e); i++)
                {
                    if(e % i == 0)
                    {
                        sumForThisE += (i + (e / i));

                        if(i == e / i) divCount++;
                        else divCount += 2;

                        if(divCount > 4) { bad = true; break; }
                    }
                }

                if(!bad && divCount == 4) res += sumForThisE;
                else sumForThisE = 0;
                
                dp[e] = sumForThisE;
            }
        }

        return res;
    }
};
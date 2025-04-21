class Solution
{
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        long long mini = 0, mexi = 0, cur = 0;
        for(auto e : differences) {
            cur += e;
            mini = min(mini, cur); mexi = max(mexi, cur);
            if((mexi - mini) > (upper - lower)) return 0;
        }
        return (mini - lower + upper - mexi + 1);
    }
};
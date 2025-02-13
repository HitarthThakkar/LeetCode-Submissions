class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        multiset<long long int> ms(nums.begin(), nums.end());
        int ops = 0;
        while(ms.size() > 1)
        {
            long long int x = *(ms.begin());
            ms.erase(ms.begin());
            long long int y = *(ms.begin());
            ms.erase(ms.begin());
            if(x >= k) return ops; else ops++;
            ms.insert((min(x, y) * 2) + max(x, y));
        }
        return ops;
    }
};
class Solution
{
public:
    bool primeSubOperation(vector<int>& nums)
    {
        vector<int> primes(1005, 1); primes[0] = 0; primes[1] = 0; set<int> pList;
        for (int i = 2; i < primes.size(); i++)
            if (primes[i]) for (int k = (2 * i); k < primes.size(); k += i) primes[k] = 0;
        for (int i = 0; i < primes.size(); i++) if (primes[i]) pList.insert(i);
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= nums[i + 1]) {
                auto it = pList.lower_bound(((nums[i] - nums[i + 1]) + 1));
                if(it == pList.end()) return false;
                if ((*it) < nums[i]) nums[i] -= (*it); else return false;
            }
        }
        return true;
    }
};
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        // Not OG, Ugly number II extension
        /* 
            Not heap, but the structure kinda like "Merge K sorted lists",
            the difference being there we were given the list initially, so ez,
            but here we have 1 only when starting then we build up list smartly
            taking smallest (just like that one) and then each ppl who were
            corresponding to that smallest are having theie indice incremented.
            THING TO UNDERSTAND IS ALSO THAT NUMBERS ARE GENERATED SORTED
            AND THUS WHENEVER DUPLICATES COME THEY DO IN SAME TIME, SEE UGLY NUMBER II
            FOR UNDERSTANDING THIS BETTER. THAT EDITORIAL ALSO HAS FORMAL PROOF BY
            INDUCTION FOR THIS MATTER.
        */
        
        int p = primes.size();
        vector<long long> nums(1, 1), indices(p, 0);
        for(int i = 1; i < n; i++)
        {
            long long next_num = 1e18;
            for(int i = 0; i < p; i++)
                next_num = min(next_num, nums[indices[i]] * primes[i]);
            nums.push_back(next_num);
            for(int i = 0; i < p; i++)
                if(next_num == nums[indices[i]] * primes[i])
                    indices[i]++;
        }
        return nums[n - 1];
    }
};
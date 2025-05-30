class Solution
{
public:
    int minimumDifference(vector<int>& nums)
    {
        // Meet in the middle (Aryan Mittal)

        int N = nums.size();
        int n = (N / 2);

        // We do not care about other 'n' numbers, choosing first 'n' numbers will
        // automatically guarentee other 'n' in second array.
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Even in best case only DP will have (2^N) i.e. 2^30 which is BAD.
        // So, meet in the middle says do ((2^15) + (2^15)) which is affordable.
        vector<vector<int>> left(n + 1), right(n + 1);

        // Now we will take left 'n' ppl and right 'n' ppl and generate all subsets of it.
        // Our first 'n' numbers can be FROM all of the left 'n' TO all of the right 'n'.
        for(int mask = 0; mask < (1 << n); mask++)
        {
            // For each mask, we would get 2 things for left and right both
            // 1) how many ppl are there in left/right for each mask [Same for left and right]
            // 2) sum of left and right after taking this mask

            int sz = 0;
            int lsum = 0;
            int rsum = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    sz++;
                    lsum += nums[i];
                    rsum += nums[i + n];
                }
            }

            // saving that sum in that size of left and right
            left[sz].push_back(lsum);
            right[sz].push_back(rsum);
        }

        /*
        We have now 'left' array, having each possible size and sum for that size stored.
        for each left sum if we can find the 'best-fit' right sum somehow.
        HOW IS RIGHT FIT DETERMINED ?
        1) SIZE
        each mask had size (out of n) and sum
        we have to make total size 'n' for first final array so
        for each left size 'sz' we find right of 'n - sz' having best sum fit.
        basically for each chosen left's size 'sz' we can take right's 'n-sz' cuz
        total size of both should be 'n' cuz that's the size of our first final array.
        2) SUM
        what does best sum fit mean?
        we need final array_1 sum == final array_2 sum [as close as possible]
        for that both should be (total / 2), where total is whole nums array's sum.
        so we need (left's sum + right's sum) == (total / 2) in best case
        so if some left's sum is 'x' then corresponding right's sum should be;
            y = ( total - (2 * x) ) / 2 [Simple math]
        so for each left ppl we have size and sum to satisfy and then we get ans.
        size is simple constraint we can just check the corresponding size.
        but to find best 'y' for some 'x' we cant use linear but we can Binary Search it.
        so sort all right's ppl and for all left check best right and update answer accordingly.
        */

        for(int sz = 0; sz <= n; sz++)
        {
            sort(right[sz].begin(), right[sz].end());
        }

        // initializing result with minimum of 2 border cases which are
        // 1) all 'n' from left and 0 from right
        // 2) all 'n' from right and 0 from left
        int result = min(abs(total - (2 * left[n][0])), abs(total - (2 * right[n][0])));

        // now other cases

        for(int sz = 1; sz < n; sz++)
        {
            for(auto &x : left[sz])
            {
                // getting best fit 'y' for each 'x'

                int y = (total - (2*x)) / 2;
                int rsz = n - sz;

                auto &v = right[rsz];

                auto itr = lower_bound(v.begin(), v.end(), y);

                if(itr != v.end())
                {
                    result = min(result, abs(total - (2 * (x + *itr))));
                }

                if(itr != v.begin())
                {
                    itr--;
                    result = min(result, abs(total - (2 * (x + *itr))));
                }
            }
        }

        return result;
    }
};
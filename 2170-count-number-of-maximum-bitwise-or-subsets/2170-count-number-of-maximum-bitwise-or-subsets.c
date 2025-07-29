/*
    Basic solution simple recursion, gets accepted on LC but not on Mind

    int recur(int i, long long int cur, long long int target, int* nums, int n)
    {
        if(i == n)
        {
            if(cur == target) return 1;
            return 0;
        }

        int res = 0;

        res += recur(i + 1, cur | nums[i], target, nums, n);
        res += recur(i + 1, cur, target, nums, n);

        return res;
    }

    int countMaxOrSubsets(int* nums, int n)
    {
        long long int target = 0;
        for(int i = 0; i < n; i++) target |= nums[i];
        return recur(0, 0, target, nums, n);
    }
*/

/*

    // Here we can observe overlapping subproblems.
    // state : [ind][currentOR]

    int recur(int i, int cur, int target, int* nums, int n, int dp[n][target + 1])
    {
        if(i == n)
        {
            if(cur == target) return 1;
            return 0;
        }

        if(dp[i][cur] != -1) return dp[i][cur];

        int res = 0;

        res += recur(i + 1, cur | nums[i], target, nums, n, dp);
        res += recur(i + 1, cur, target, nums, n, dp);

        return dp[i][cur] = res;
    }

    int countMaxOrSubsets(int* nums, int n)
    {
        int target = 0;
        for(int i = 0; i < n; i++) target |= nums[i];
        int dp[n][target + 1];
        for(int i = 0; i < n; i++) for(int j = 0; j < target + 1; j++) dp[i][j] = -1;
        return recur(0, 0, target, nums, n, dp);
    }

    // We can do a small little beautiful optimization, which is stopping early
    // when already reached max_OR.

    @cache
    def recur(cur_or, i):
        if i == n and cur_or != target:
            return 0
        if cur_or == target:    # Here we have to not reached i == n but OR is already done.
            return 2 ** (n-i)   # So we can take all subsets from here, i.e. 2^(n-i)
        
        cnt = 0
        cnt += recur(cur_or|nums[i], i+1)
        cnt += recur(cur_or, i +1)
        return cnt

    def main(some arguements here):
        # some driver code calling recur

*/

/*
    // Recursive had 2^n time and n space
    // This removes that n space and takes (n * 2^n) time

    int countMaxOrSubsets(int* nums, int n)
    {
        int target = 0;
        for(int i = 0; i < n; i++) target |= nums[i];

        int goodSubsets = 0;

        for(int mask = 0; mask < (1 << n); mask++)
        {
            int cur = 0;

            for(int i = 0; i < n; i++)
            {
                if((mask >> i) & 1) cur |= nums[i];
            }

            if(cur == target) goodSubsets++;
        }

        return goodSubsets;
    }
*/



// We strive for better solution.
// this is bottom up version lemme explain that
// basically we start with dp[0] = 1
// which shows that in order to make the OR value 0, we have 1 subset i.e. empty subset
// we cannot have more than 1 subset for dp[0]
// now what we are doing is traversing elements one by one
// and for each element, going to all possible ORs that have been achieved and
// then ORing with them. [dry running and thinking will help here]
// also we are going backwards from mex to 0 in j cuz we want to count stuff correctly.
// so basically all available ors [0 to mex] are there
// and for all ppl we just doing or with all previously done.
// like for i = 0, we have mex encountered till now is 0, so we'll just or it with 0 | nums[0]
// and so on in which dp will take care of counts.
// if still not understand give code to gpt it has very good experience to teach losers.

int countMaxOrSubsets(int* nums, int n)
{
    int mex = 0;
    int dp[1 << 17] = {0};

    dp[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = mex; j >= 0; j--)
        {
            dp[j | nums[i]] += dp[j];
        }

        mex |= nums[i];
    }

    return dp[mex];
}





// do u remember i called the last solution "better" ? 
// is there a best ?
// better than that approach ? 

// yes ofc.
// but its time consuming for me for now.
// i would not spend 3 hrs a day writing essays for potd only.
// so skipping the most optimal and clever bit manipulation + inclusion_exclusion approach.
// take care of it urself.

/*


https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/5928846/the-actual-optimal-solution-o-n-max-time-o-1-space


Approach
Find the maximum OR value, then efficiently count the number of subsets of the array that do not have the maximum OR value using inclusion-exclusion.

Here is a good resource to learn about the principle of inclusion-exclusion: https://artofproblemsolving.com/wiki/index.php/Principle_of_Inclusion-Exclusion

Complexity
Time complexity:
O(NM), where M is the max or value, and N is the size of nums.

Space complexity:
O(1), unlike the dp solution.


cpp code

#pragma GCC target("popcnt")
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) { //O(n*maxValue) time, O(1) storage
        int maxOr=0; 
        for(int n:nums) maxOr|=n;
        int numberOfBadSubsets = 0; //bad subset means subset whose OR is less than maxOR
        for(int mask=maxOr;mask; mask=(mask-1)&maxOr){ //iterates over subsets of the set bits of the maxOr
            int cnt = 0; 
            for(int n:nums) if(!(n&mask)) cnt++; //counts elements of nums that have all 0s in the positions that are 1s in the current mask
            numberOfBadSubsets += (__builtin_popcount(mask)%2 ? 1 : -1)*((1<<cnt)-1); //inclusion exclusion
        }
        return (1<<nums.size())-1- numberOfBadSubsets;//total number of subsets minus number of bad subsets
    }
};


understand it worship it.

it also contains OP bitwise trick. (mask = (mask - 1) & maxOr)
and inclusion exclusion ofc.


*/
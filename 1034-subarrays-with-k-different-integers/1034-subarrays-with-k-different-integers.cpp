class Solution
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        // Co_Author : NeetCodeIO {GOAT}

        /*
            Idea of Co_Author :-
            [1] When applying simplest sliding window thing, we get the answer as
                4 for the first example test case instead of 7.
            [2] What were the subarrays we missed ?
            [3] After some analysis we get to know that the issue is, we are TRYING
                to count all subarrays which are starting from 'left', but we miss
                them due to the nature of the problem. We cannot do that correctly in any way.

            [4] We cannnot change the nature of the problem, but we CAN change the
                nature of our solution.

            [5] We can TRY to count subarrays ending at some index ('right' ofc).
            [6] The same issue won't appear ? Let's check. YES, it would.
            [7] BUT we are in some better position if we see what are we missing now.
            [8] How can we include the subarrays we are missing ?
            [9] Is it easier than previous to include the missing subarrays ?

            --> Largest subarray having K different integers AND 
                Smallest subarray having K different integers.
                [ 3 Pointers Sliding Window ]
        */

        /*
            VALID means it has exactly 'k' unique integers.
            INVALID means it has more than 'k' unique integers.
        */

        int n = nums.size();
        int result = 0;
        int l_far = 0;      // Longest subarray with K different integers   -> [l_far, right]
        int l_near = 0;     // Smallest subarray with K different integers  -> [l_near, right]
        int right = 0;      // Subarrays ending at 'right' index

        unordered_map<int, int> mp;     // 'K' different

        while(right < n)
        {
            mp[nums[right]]++;

            bool invalidness = false;

            /*
                Shrinking the window has 2 reasons :
                [1] Window is INVALID (> K unique) and thus making it VALID is neccesary
                [2] Window is valid, but [l_near to right] is not smallest, we have to
                    increment l_near to get to the smallest valid one.
            */

            // #[1] INVALID
            {

                while(mp.size() > k)
                {
                    // l_near to right is INVALID.
                    // So, automatically l_far to right is also INVALID.
                    invalidness = true;

                    mp[nums[l_near]]--;

                    if(mp[nums[l_near]] == 0) mp.erase(nums[l_near]);

                    l_near++;
                }

                if(invalidness)
                {
                    // VALID means it has exactly 'k' unique integers.
                    // Meaning we got > k elements and now we resolved that by
                    // moving l_near to right and shrinking our window.
                    // What about l_far in this case?
                    // l_near was just moved for making the window VALID again,
                    // not for getting smallest VALID.
                    // So, the current l_near is actually the
                    // Largest AND smallest VALID subarray.
                    // so basically l_far is l_near (in same configuration as we started)
                    l_far = l_near;
                }
            }

            // #[2] Smallest
            {
                while(mp[nums[l_near]] > 1)
                {
                    // mp[nums[l_near]] is > 1. means, EVEN IF we delete this l_near element,
                    // we will still have at-least 1 occurence of that same one somewhere in middle.
                    // in other words, this one is duplicate.
                    // removing this will not decrease our count of unique integers.
                    // We would still have subarray of K unique, but smaller in size.
                    // We can do that until we reach an index where the element's
                    // freq is 1. We cannot remove that one cuz that will decrease our
                    // unique integer count and make it k - 1.
                    // We dont want that.
                    // We need smallest subarray with K distinct integers.
                    // So we will stop when mp[nums[l_near]] == 1.
                    mp[nums[l_near]]--;
                    l_near++;
                }
            }

            // Updating the count if map has exactly 'K' distinct.
            if(mp.size() == k)
            {
                // We have exactly k distinct integers from [l_near to right] AND [l_far to right]
                // total subarrays which we can make from that is (l_near - l_far + 1).
                result += (l_near - l_far + 1);
            }

            right++;
        }

        return result;
    }
};
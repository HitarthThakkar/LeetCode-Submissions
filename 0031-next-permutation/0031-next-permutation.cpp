class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();    // basic faltu stuff on this line

        /* "RAJ" -> "RAX" -> "RBX" */
        // Longer the prefix match, better.
        // Longest Prefix match.
        // Find Greater Element right of the current, BUT
        // but just great. Not too much, cause we just want 'next' permutation.

        /*
            -----------------------IMPORTANT---------------------------
            NOTE THAT THE ARRAY FROM "IND + 1" TO "N" IS REVERSE SORTED.
        */

        int ind = -1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }

        if(ind == -1)
        {
            // Last Permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        // We have 'ind' which needs to be changed (more precisely swapped) with
        // the just greater element on the right to it.

        for(int i = n - 1; i > ind; i--)
        {
            // Only comparing with nums[ind] to check cause
            // the array from (n - 1) to (ind + 1) is monotonically
            // decreasing and that also suggests we can do binary search.
            // but that's not main idea here so just doing linear.
            if(nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Now we have "ind + 1" to "n - 1" array sorted monotonically decreasing.
        // so we can sort it by just reversing it.

        reverse(nums.begin() + ind + 1, nums.end());
    }
};
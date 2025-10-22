class Solution
{
public:

    int findBestFROMArray(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> freq;
        for(auto e : nums) freq[e]++;

        int maxFreq = 0;

        for(auto e : freq)
        {
            // let's make the 'e' max freq person.
            int val = e.first;

            int left = lower_bound(nums.begin(), nums.end(), val - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), val + k) - nums.begin();
            right--;

            int curFreq = min(right - left + 1, numOperations + e.second);

            maxFreq = max(maxFreq, curFreq);
        }

        return maxFreq;
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        // another approach, different than all prev submissions

        /*

        IDEA :  what if we had infinite numOps? meaning we can make all the
                elements equal in a [2k] range, so sort the array and go
                sliding window approach, extend window until (left + 2k >= right)
                and find max length and all those elements in that length can be
                converted to some same element with 'length' number of operations.
            
            BUT we do not have infinite operations, and we cannot directly apply
            the last technique in this case, as we can have some original elements
            in the array. E.G. -> [5, 10, 10, 10, 10, 15] k = 5, numOps = 2.
            We can get answer = 6 which is >> numOps due to so many 10's originally
            present in the array itself.

            WHEN WILL THIS '10' TYPE OF CASE OCCUR??
            ->  When the final element which is going to become max freq is
                already present in the original array itself.

            Another case to think of before moving fwd :
            nums = [88, 53]; k = 27; numOps = 2.
            ANSWER = 2

            So, do 2 approaches :

            1)  for all the elements that are in the array originally at start,
                make each one a potential future candidate and find how much max
                answer we can get [not too hard]

            2)  for all other elements which are not in the array and might become
                majority, the answer can be found out using the sliding window
                technique with length <= numOperations, as we can't do more
                operations than that and as we have divided the problem in a way
                such any element which was originally present would not become
                majority and thus to make an 'outsider' a majority, we have to
                do all the 'length' number of operations and thus
                length <= numOperations holds. that [88, 53] case follows this idea.

            3) return max of ans_1 and ans_2.
        */

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Function to do part_1
        // i.e. making all original elements max freq one by one

        int arrayValueMaxFreq = findBestFROMArray(nums, k, numOperations);

        // Part_2 be slidin

        int left = 0;
        int otherValueMaxFreq = 0;

        for(int right = 0; right < n; right++) {
            // Making window valid enough
            while((nums[right] * 1LL) > (nums[left] + 0LL + (2 * k)) ) {
                left++;
            }

            otherValueMaxFreq = max(otherValueMaxFreq, right - left + 1);

            if(otherValueMaxFreq >= numOperations) {
                otherValueMaxFreq = numOperations;
                break;  // cant do better than that.
            }
        }

        return max(arrayValueMaxFreq, otherValueMaxFreq);
    }
};
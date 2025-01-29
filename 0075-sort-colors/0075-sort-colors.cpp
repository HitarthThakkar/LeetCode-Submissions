class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        // Dutch National Flag Algorithm

        /*
                            -: RULES OF DOUBLE DUNGON (cartenon temple) V/S DUTCH DUNGEON (dnf algo) :-
            (1) Thou shall worship God.                                         i.e.; [0 to low - 1]      -> all zeros
            (2) Thou shall praise God.                                          i.e.; [low to mid - 1]    -> all ones
            (3) Thou shall prove thy faith.                                     i.e.; [mid to high]       -> Unsorted shit
            (4) Those who fail to obey these commandments shall not be spared.  i.e.; [high + 1 to n - 1] -> all twos
        */

        // At starting, whole array is unsorted.
        // i.e.; mid = 0 to high = n - 1 is unsorted.
        // low = 0 and so 0 to low - 1 has all zeros, which logically is true.

        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        // while there is atleast one element from the "mid to high" 'unsorted' part
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                // ARE THE RULES OF DUNGEON FOLLOWED?
                // NO.
                // at mid index there is zero.
                // BUT its actual position should be at max (low - 1).
                // but actually 0 to low - 1 is already filled whole with zeros.
                // so at nums[low] we can put zero.
                // ...
                // but what about the element which is currenlty at nums[low]?
                // its 1 or 0.                                                 [IT CAN NEVER BE 2. {!!! THINK WHY !!!} ]
                // but now low will contain zero as we've encounterd new zero at nums[mid]
                // ...
                // nums[low] = nums[mid] and then low++
                // and simultaneously nums[mid] = nums[low] and then also mid++
                // see whether all rules of DNF Dungeon are still followed or not.
                // If yes then you're still alive.
                // If not dryrun PEN_PAPER.

                if(nums[low] == 2)  // If nums[low] == 2 this code will not pass.
                {
                    // this never gets executed, cause;
                    // we know nums[mid] = 0, right?
                    // right?
                    // that's why we come into this IF statement.
                    // and now if nums[mid] = 0 then nums[low] can never be 2.
                    // It canbe 0 or 1 though.
                    // just dry run first example test case pen and paper and you'll get this shit through ur head.
                    nums[0] = 69;
                    return;
                }

                swap(nums[low], nums[mid]);
                low++;
                mid++;
                // NOTE THAT [MID TO HIGH] PART WAS UNSORTED AND WE REDUCES THAT PART BY 1 LENGTH AND
                // AND MADE IT [MID + 1 TO HIGH] BY INCREMENTING MID.
            }
            else if(nums[mid] == 1)
            {
                // ARE THE RULES OF DUNGEON FOLLOWED?
                // NO.
                // at mid, there is 1, but 1 should belong to (mid - 1) index at max.
                // other rules are fine.
                // mid++ will resolve this simply.
                mid++;
                // NOTE THAT [MID TO HIGH] PART WAS UNSORTED AND WE REDUCES THAT PART BY 1 LENGTH AND
                // AND MADE IT [MID + 1 TO HIGH] BY INCREMENTING MID.
            }
            else
            {
                // ARE THE RULES OF DUNGEON FOLLOWED?
                // NO.
                // at mid, there is 2, which should belong to (high + 1) inedx at minimum.
                // high + 1 to end already contains all twos.
                // we cannot do anything there.
                // so push it at that high index and then do high--
                // ...
                // but what about the element at nums[high]?
                // It canbe 0 OR 1 OR 2.
                // just swap mid with high and then not increment mid.
                // we'll see what there is now on mid in the next turn.
                swap(nums[mid], nums[high]);
                high--;
                // NOTE THAT [MID TO HIGH] PART WAS UNSORTED AND WE REDUCES THAT PART BY 1 LENGTH AND
                // AND MADE IT [MID TO HIGH - 1] BY DECREMENTING HIGH.
            }
        }
    }
    // AT EACH STEP IN WHILE LOOP,
    // NO MATTER WHICH ELEMENT IS AT NUMS[MID],
    // WE REDUCE THE LENGTH OF MID TO HIGH BY 1.
    // INITIAL LENGTH OF MID TO HIGH WAS 'N'.
    // SO IN 'N' STEPS WE'LL REDUCE IT TO ZERO, AND HENCE SORT IT.
    // SO O(N) TIME COMPLEXITY.
    // SPACE COMPLEXITY IS VERY HIGH DUE TO THESE COMMENTS TAKING ATLEAST 10 TIMES OF THE SPACE OF SOLUTION.
    // CHECK THE PREVIOUS CRISPY 3 LINE SOLUTION TO SEE THE GOOD SPACE COMPLEXITY.
};
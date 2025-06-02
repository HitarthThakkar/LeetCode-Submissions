class Solution
{
public:
    bool isIdealPermutation(vector<int>& nums)
    {
        /*
            Huh ! Just a 3 line simple looking code ?
            The question must be simple, right ?
            THE QUESTION MUST BE SIMPLE, RIGHT ?
            ****************** Trivial INFO ******************
            There is atleast 2 hr of mental effort after this cute looking 3 line code.
            {I swear its not cute, it have consumed my flesh, brother !}
        */
        for (int i = 0; i < nums.size(); i++)
            if (abs(nums[i] - i) > 1) return false;
        return true;
    }
};
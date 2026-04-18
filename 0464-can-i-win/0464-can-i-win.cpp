class Solution
{
public:
    bool recur(int runningTotal, int choice, int desiredTotal, vector<int> &dp)
    {
        if (dp[choice] != -1) return dp[choice];

        int temp = choice;
        while (temp)
        {
            int pos = __builtin_ctz(temp);

            // picked the number (pos + 1)
            int newChoice = choice & ~(1 << pos);

            // I can "force" the win if (I win || opponent loses)
            if (runningTotal + pos + 1 >= desiredTotal || !recur(runningTotal + pos + 1, newChoice, desiredTotal, dp))
            {
                return dp[choice] = 1;
            }

            temp &= (temp - 1);
        }

        return dp[choice] = 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (desiredTotal == 0) return true;

        int maxPossibleTotal = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (maxPossibleTotal < desiredTotal) return false;

        /*
            > be me
            > read que and start with the state as basic recur(int turn, int runningTotal, vector<int> choices)
            > get TLE
            > think of memoizing it, but realize that memoizing a vector is not possible
            > think of bitmasking the 'choices' vector into a 'choice' integer and do it
            > run recursive code just to get TLE and confirm logic is working
            > try to memoize it now as [turn][runningTotal][choice]
            > only to test and realize that worst case is actually [2][210][2^20], MLE
            > realize that runningTotal is not necessary in a state, (turn, choice) is enough to represent unique state
            > make changes to code with confidence and make 2d dp cuz [2][2^20] which is 2^21 < 10^7, confidence upto sky
            > actually get an AC and good runtime
            > think that ur smart and can make 1d dp instead of 2d by using the rightmost bit of choice as the turn
            > but by this time you're too tired and get idea of putting those trash models at test
            > goto incognito chatgpt and give that AC code and tell it to make 1d and also not to make any mistake
            > chatgpt roasts you by telling that turn is also not nesessary in a state and choice alone can suffice
            > underestimate incognito chatgpt and think he's wrong, must've made a mistake, ask for code and explanation from him
            > ACTUALLY think while seeing chatgpt generated explanation and code and ACTUALLY realize that he's right
            > paste the generated code and write this sorta comment in it for future-you after getting low diffed by incognito gpt
            > submit the gpt generated code, get AC and call urself coder
        */

        int choice = (1 << maxChoosableInteger) - 1;
        vector<int> dp(choice + 1, -1);

        return recur(0, choice, desiredTotal, dp);
    }
};
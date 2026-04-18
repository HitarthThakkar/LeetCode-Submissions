class Solution
{
public:
    bool recur(int turn, int runningTotal, int choice, int desiredTotal, vector<vector<int>> &dp) {
        if(runningTotal >= desiredTotal) return turn;
        if(dp[turn][choice] != -1) return dp[turn][choice];
        int temp = choice;
        if(turn) {
            while(temp) {
                int pos = __builtin_ctz(temp);
                choice &= ~(1 << pos);
                bool instaWin = !recur(!turn, runningTotal + pos + 1, choice, desiredTotal, dp);
                choice |= (1 << pos);
                if(instaWin) return dp[turn][choice] = false;
                temp &= (temp - 1);
            }
            return dp[turn][choice] = true;
        }
        else {
            while(temp) {
                int pos = __builtin_ctz(temp);
                choice &= ~(1 << pos);
                bool instaWin = recur(!turn, runningTotal + pos + 1, choice, desiredTotal, dp);
                choice |= (1 << pos);
                if(instaWin) return dp[turn][choice] = true;
                temp &= (temp - 1);
            }
            return dp[turn][choice] =false;
        }
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0) return true;
        int maxPossibleTotal = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if(maxPossibleTotal < desiredTotal) return false;
        int choice = (1 << maxChoosableInteger) - 1;
        vector<vector<int>> dp(2, vector<int> (choice + 1, -1));
        return recur(0, 0, choice, desiredTotal, dp);
    }
};
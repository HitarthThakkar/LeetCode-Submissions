class Solution
{
public:
    int recur(int index, int prev_index, vector<string> &strs, vector<vector<int>> &dp) {
        if(index == strs[0].length()) return 0;

        if(dp[index + 1][prev_index + 1] != -1) return dp[index + 1][prev_index + 1];

        // deleting this col
        int len = recur(index + 1, prev_index, strs, dp);

        // taking this col
        if(prev_index == -1) len = max(len, 1 + recur(index + 1, index, strs, dp));
        else {
            bool thisColIsBad = false;
            for(int i = 0; i < strs.size(); i++) {
                if(strs[i][index] < strs[i][prev_index]) thisColIsBad = true;
            }
            if(!thisColIsBad) {
                len = max(len, 1 + recur(index + 1, index, strs, dp));
            }
        }

        return (dp[index + 1][prev_index + 1] = len);
    }

    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].length();
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, -1));
        return (n - recur(0, -1, strs, dp));
    }
};
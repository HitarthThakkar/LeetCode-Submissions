class Solution
{
public:
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &palDP)
    {
        if(i >= j) return true;
        if(palDP[i][j] != -1) return palDP[i][j];
        if(s[i] != s[j]) return palDP[i][j] = 0;
        return palDP[i][j] = isPalindrome(i + 1, j - 1, s, palDP);
    }
    int recur(int i, int j, string &s, vector<vector<int>> &dp, vector<vector<int>> &palDP)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(i, j, s, palDP)) return dp[i][j] = 0;
        // cout << i << " " << j << endl;
        int result = INT_MAX;
        for(int k = i; k < j; k++)
        {
            if(isPalindrome(i, k, s, palDP))
            {
                if(dp[i][k] == -1) dp[i][k] = recur(i, k, s, dp, palDP);
                if(dp[k + 1][j] == -1) dp[k + 1][j] = recur(k + 1, j, s, dp, palDP);
                result = min(result, 1 + dp[i][k] + dp[k + 1][j]);
            }
        }
        return dp[i][j] = result;
    }
    int minCut(string s)
    {
        // reverse(s.begin(), s.end());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        vector<vector<int>> palDP(n, vector<int> (n, -1));
        return recur(0, n - 1, s, dp, palDP);
    }
};







// class Solution {
// public:
//     int recur(int i, int j, string &s, vector<vector<int>> &dp, vector<vector<int>> &palDP)
//     {
//         if (dp[i][j] != -1) return dp[i][j];
//         if (palDP[i][j]) return dp[i][j] = 0;  // No cuts needed if the substring is a palindrome
//         int result = INT_MAX;
//         for (int k = i; k < j; k++)
//         {
//             // Use previously computed results to avoid recomputing subproblems
//             if (dp[i][k] == -1) dp[i][k] = recur(i, k, s, dp, palDP);
//             if (dp[k + 1][j] == -1) dp[k + 1][j] = recur(k + 1, j, s, dp, palDP);
//             result = min(result, 1 + dp[i][k] + dp[k + 1][j]);
//         }
//         return dp[i][j] = result;
//     }

//     int minCut(string s)
//     {
//         int n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         vector<vector<int>> palDP(n, vector<int>(n, 0));  // Initialize palDP with 0s

//         // Precompute palDP
//         // Base case: Single character substrings are palindromes
//         for (int i = 0; i < n; ++i)
//         {
//             palDP[i][i] = 1;  // Single character is always a palindrome
//         }

//         // Base case: Two consecutive characters are palindromes if they are equal
//         for (int i = 0; i < n - 1; ++i)
//         {
//             if (s[i] == s[i + 1]) palDP[i][i + 1] = 1;
//         }

//         // Precompute palDP for substrings longer than 2
//         for (int length = 3; length <= n; ++length)  // length of the substring
//         {
//             for (int i = 0; i <= n - length; ++i)
//             {
//                 int j = i + length - 1;
//                 // If the characters at the ends are equal and the inner substring is a palindrome
//                 if (s[i] == s[j] && palDP[i + 1][j - 1] == 1)
//                 {
//                     palDP[i][j] = 1;
//                 }
//             }
//         }

//         return recur(0, n - 1, s, dp, palDP);
//     }
// };
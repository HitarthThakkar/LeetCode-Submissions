class Solution
{
public:
    int dp[100000][2][2][2];
    int mod = 1e9 + 7;

    int recur(int i, int n, int ab, int lt1, int lt2)
    {
        if(i == n) return 1;
        if(dp[i][ab][lt1][lt2] != -1) return dp[i][ab][lt1][lt2];
        int total = 0;
        total += (recur(i + 1, n, ab, lt2, 0) % mod); total %= mod;
        if(ab == 0) total += (recur(i + 1, n, 1, lt2, 0) % mod); total %= mod;
        if(lt1 != 1 || lt2 != 1) total += (recur(i + 1, n, ab, lt2, 1) % mod); total %= mod;
        return dp[i][ab][lt1][lt2] = (total % mod);
    }

    int checkRecord(int n)
    {
        memset(dp, -1, sizeof dp);
        return recur(0, n, 0, 0, 0);
    }
};
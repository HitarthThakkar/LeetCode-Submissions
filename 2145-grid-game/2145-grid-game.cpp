class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> p1(n, 0), p2(n, 0);
        for(int i = 1; i < n; i++)
            p1[i] = p1[i - 1] + grid[0][n - i];
        for(int i = 1; i < n; i++)
            p2[i] = p2[i - 1] + grid[1][i - 1];
        long long ans = 1e18;
        for(int i = 0; i < n; i++)
            ans = min(ans, max(p1[i], p2[n - i - 1]));
        return ans;
    }
};
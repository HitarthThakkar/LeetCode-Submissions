class Solution {
public:
    int m, n;
    vector<vector<pair<long long, long long>>> dp;

    // This is GOOD DP problem. I've seen many but this one still feels different.
    // It's like that (Maximum Product Subarray + DP) into one GOOD problem. <3

    pair<long long, long long> recur(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (i >= m || j >= n) {
            return {LLONG_MIN, LLONG_MAX};
        }

        if (dp[i][j].first != LLONG_MIN) return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        auto right = recur(i, j + 1, grid);
        auto down = recur(i + 1, j, grid);

        vector<long long> vals;

        if (right.first != LLONG_MIN) {
            vals.push_back(grid[i][j] * right.first);
            vals.push_back(grid[i][j] * right.second);
        }
        if (down.first != LLONG_MIN) {
            vals.push_back(grid[i][j] * down.first);
            vals.push_back(grid[i][j] * down.second);
        }

        for (auto v : vals) {
            maxi = max(maxi, v);
            mini = min(mini, v);
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        long long mod = 1e9 + 7;
        auto res = recur(0, 0, grid);

        if (res.first < 0) return -1;
        return res.first % mod;
    }
};
#define pai pair<int, int>
class Solution
{
public:
    int recur(int ind, int lti, int left, vector<pai> &arr, vector<vector<int>> &dp)
    {
        // cout << ind << " " << lti << " " << left << endl;
        if(left == 0) return lti;
        if(ind == arr.size()) return -1;
        if(dp[ind][left] != -1) return dp[ind][left];
        int val = -1;
        if(arr[ind].first <= left)
            val = recur(ind + 1, max(lti, arr[ind].second), left - arr[ind].first, arr, dp);
        if(val == -1) val = 1e9;
        int val2 = recur(ind + 1, lti, left, arr, dp);
        if(val2 == -1) val2 = 1e9;
        int vv = min(val, val2);
        if(vv == 1e9) { dp[ind][left] = 1e9; return -1; }
        return  dp[ind][left] = vv;
    }
    int isSubsetSum(vector<pair<int, int>>& arr, int target)
    {
        vector<vector<int>> dp(arr.size(), vector<int> (target + 1, -1));
        int res = recur(0, -1, target, arr, dp);
        return res;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        vector<vector<pair<int, int>>> vvp(n);
        int qp = 1;
        for(auto q : queries)
        {
            int l = q[0];
            int r = q[1];
            int val = q[2];
            for(int i = l; i <= r; i++) vvp[i].push_back({val, qp});
            qp++;
        }
        int i = 0;
        int ans = 0;
        for(auto vec : vvp)
        {
            int target = nums[i];
            if(target != 0)
            {
                int ltknnd = isSubsetSum(vec, target);
                if(ltknnd == -1) return -1;
                else ans = max(ans, ltknnd);
            }
            i++;
        }
        return ans;
    }
};
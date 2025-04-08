class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int ind = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s.find(nums[i]) == s.end()) s.insert(nums[i]);
            else { ind = i; break; }
        }
        if(ind == -1) return 0;
        else {
            int ans = 0;
            ind++;
            if(ind % 3 != 0) ans++;
            ans += (ind / 3);
            return ans;
        }
        return -1e5;
    }
};
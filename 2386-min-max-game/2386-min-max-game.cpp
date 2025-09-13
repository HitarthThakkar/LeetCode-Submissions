class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> newnums;
        bool flag = true;
        for(int i = 0; i < nums.size(); i += 2)
        {
            if(flag) newnums.push_back(min(nums[i], nums[i + 1]));
            else newnums.push_back(max(nums[i], nums[i + 1]));
            flag = !flag;
        }
        return minMaxGame(newnums);
    }
};
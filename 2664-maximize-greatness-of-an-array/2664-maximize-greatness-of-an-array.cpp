class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int ans = 0;
        multiset<int> ms;
        for(auto ele : nums) ms.insert(ele);
        for(auto ele : nums)
        {
            auto it = ms.upper_bound(ele);
            if(it != ms.end())
            {
                ans++;
                ms.erase(it);
            }
        }
        return ans;
    }
};
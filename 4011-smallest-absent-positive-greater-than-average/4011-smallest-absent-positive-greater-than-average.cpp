class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        map<int, int> mp;
        for(auto e : nums){ sum += e; mp[e]++; }
        sum /= (n * 1.0);
        for(int i = 1; i < 1000; i++)
        {
            if(i > sum && mp.find(i) == mp.end()) return i;
        }
        return -1;
    }
};
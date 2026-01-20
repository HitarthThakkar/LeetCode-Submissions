class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(auto e : nums)
        {
            if(e == 2) { res.push_back(-1); continue; }
            int ct = 0;
            while(e & 1) { e >>= 1; ct++; }
            e <<= ct;
            e += pow(2, ct - 1) - 1;
            res.push_back(e);
        }
        return res;
    }
};
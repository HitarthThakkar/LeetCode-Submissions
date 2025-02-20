class Solution
{
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        string ans = "";
        int ind = 0;
        for(auto s : nums)
            if(s[ind++] == '1') ans += '0'; else ans += '1';
        return ans;
    }
};
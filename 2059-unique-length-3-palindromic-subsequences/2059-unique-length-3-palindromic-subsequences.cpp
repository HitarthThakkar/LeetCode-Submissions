class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        unordered_map<char, pair<int, int>> mp;
        for(int i = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end()) mp.insert({s[i], {i, -1}});
            else mp[s[i]].second = i;
        }
        int ans = 0;
        for(auto ele : mp)
        {
            unordered_set<char> set;
            for(int i = ele.second.first + 1; i < ele.second.second; i++)
                set.insert(s[i]);
            ans += set.size();
        }
        return ans;
    }
};
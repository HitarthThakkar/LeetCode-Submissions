class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        for(auto ele : s) m[ele]++;
        multimap<int, char> mp;
        for(auto ele : m) mp.insert({ele.second, ele.first});
        string ans = "";
        for(auto ele : mp) for(int i = 0; i < ele.first; i++) ans += ele.second;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
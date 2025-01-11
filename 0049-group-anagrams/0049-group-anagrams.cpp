class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs)
        {
            string hashString = "";
            vector<int> freq(26, 0);
            for(auto ele : s) freq[ele - 'a']++;
            for(auto ele : freq) hashString += ele, hashString += '#';
            mp[hashString].push_back(s);
        }
        vector<vector<string>> anagrams;
        for(auto ele : mp) anagrams.push_back(ele.second);
        return anagrams;
    }
};
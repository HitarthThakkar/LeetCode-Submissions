class Solution
{
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        set<pair<char, char>> st;
        vector<int> result;
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(auto ch1 : v) for(auto ch2 : v) st.insert({ch1, ch2});
        vector<int> pfx(words.size() + 1);
        for(int i = 0; i < words.size(); i++)
        {
            pair<char, char> pr = {words[i][0], words[i][words[i].size() - 1]};
            if(st.find(pr) != st.end()) pfx[i + 1] = pfx[i] + 1;
            else pfx[i + 1] = pfx[i];
        }
        for(auto ele : queries) result.push_back(pfx[ele[1] + 1] - pfx[ele[0]]);
        return result;
    }
};
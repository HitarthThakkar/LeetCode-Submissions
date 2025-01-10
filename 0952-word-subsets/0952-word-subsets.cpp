class Solution
{
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> mexf(26, 0); vector<string> ans;
        for(auto s : words2)
        {
            vector<int> myf(26, 0); for(auto ch : s) myf[ch - 'a']++;
            for(int i = 0; i < 26; i++) mexf[i] = max(mexf[i], myf[i]);
        }
        for(auto s : words1)
        {
            bool flag = true; vector<int> myf(26, 0); for(auto ch : s) myf[ch - 'a']++;
            for(int i = 0; i < 26; i++) if(myf[i] < mexf[i]) flag = false;
            if(flag) ans.push_back(s);
        }
        return ans;
    }
};
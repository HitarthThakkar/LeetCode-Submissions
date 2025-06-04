class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        int n = word.length();
        if(numFriends == 1) return word;
        int mexlen = (n - (numFriends - 1));
        vector<vector<int>> v(26); vector<string> vs;
        for(int i = 0; i < n; i++) v[(int) (word[i] - 'a')].push_back(i);
        for(int i = 25; i >= 0; i--) {
            if(v[i].size() > 0) {
                for(auto j : v[i]) {
                    int leftlen = n - j;
                    vs.push_back(word.substr(j, min(mexlen, leftlen)));
                }
                break;
            }
        }
        sort(vs.begin(), vs.end());
        return vs.back();
    }
};
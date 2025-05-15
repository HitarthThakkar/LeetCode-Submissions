class Solution
{
public:
    bool dist(string a, string b)
    {
        if(a.length() != b.length()) return false;
        int ct = 0;
        for(int i = 0; i < a.length(); i++) if(a[i] != b[i]) ct++;
        return (ct == 1);
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        int n = words.size();
        vector<pair<int, int>> dp(n, {1, -1});
        for(int i = 1; i < n; i++)
            for(int j = i - 1; j >= 0; j--)
                if(groups[i] != groups[j] && dist(words[i], words[j]))
                    if(dp[j].first >= dp[i].first)
                        dp[i] = {dp[j].first + 1, j};
        vector<string> answer;
        int mexind = 0;
        for(int i = 1; i < n; i++) if(dp[i].first > dp[mexind].first) mexind = i;
        int i = mexind;
        while(i != -1) {
            answer.push_back(words[i]);
            i = dp[i].second;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.length(), j = 0;
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++) {
            while(j > 0 && word[j] != word[i]) j = lps[j - 1];
            if(word[j] == word[i]) lps[i] = ++j;
        }
        int goodLen = lps[n - 1];
        while(goodLen > 0 && (n - goodLen) % k != 0) goodLen = lps[goodLen - 1];
        return ((n - goodLen) % k == 0 ? (n - goodLen) / k : (n + k - 1) / k);
    }
};
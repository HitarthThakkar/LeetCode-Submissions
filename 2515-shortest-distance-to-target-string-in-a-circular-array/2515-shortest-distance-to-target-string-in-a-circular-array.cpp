class Solution
{
public:
    int closestTarget(vector<string>& words, string target, int startIndex)
    {
        int n = words.size();
        int res = 1e9;
        for(int i = 0; i < n; i++) if(words[i] == target) res = min({res, abs(i - startIndex), n - abs(i - startIndex)});
        return (res == 1e9 ? -1 : res);
    }
};
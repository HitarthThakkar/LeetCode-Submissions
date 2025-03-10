class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++)
            {
                freq[s[j]]++;
                int mex = 0, mean = 1e9;
                for(auto el : freq)
                {
                    if(el.second > mex) mex = el.second;
                    if(el.second < mean) mean = el.second;
                }
                res += (mex - mean);
            }
        }
        return res;
    }
};
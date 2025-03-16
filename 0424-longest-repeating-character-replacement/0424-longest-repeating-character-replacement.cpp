class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> f(26, 0);
        int left = 0, right = 0, ans = 0;
        while(right < s.length())
        {
            f[s[right] - 'A']++;
            int mex = *max_element(f.begin(), f.end());
            int sum = accumulate(f.begin(), f.end(), 0);
            while(sum - mex > k)
            {
                f[s[left++] - 'A']--;
                sum--;
                mex = *max_element(f.begin(), f.end());
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
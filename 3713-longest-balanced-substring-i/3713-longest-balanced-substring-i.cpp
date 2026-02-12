class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            if(n - i < res) break;

            vector<int> v(26, 0);
            vector<int> freq(n + 1, 0);
            int ndc = 0;

            for(int j = i; j < n; j++)
            {
                int prevFreq = v[s[j] - 'a'];
                if(prevFreq == 0) ndc++;
                freq[prevFreq]--;
                v[s[j] - 'a']++;
                freq[prevFreq + 1]++;

                if(freq[prevFreq + 1] == ndc) res = max(res, j - i + 1);
            }
        }

        return res;
    }
};
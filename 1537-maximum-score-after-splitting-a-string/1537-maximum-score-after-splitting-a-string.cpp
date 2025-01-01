class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.length();
        int ttlzs = 0;

        for(auto ch : s)
        {
            if(ch == '0')
            {
                ttlzs++;
            }
        }

        int czs = 0;
        int max_score = 0;

        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == '0')
            {
                czs++;
            }

            int score = ((czs) + ((n - i - 1) - (ttlzs - czs)));

            max_score = max(max_score, score);
        }

        return max_score;
    }
};
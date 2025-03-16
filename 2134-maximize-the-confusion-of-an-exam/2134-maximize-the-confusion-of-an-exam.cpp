class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int t = 0, f = 0, left = 0, right = 0, res = 0;
        while(right < answerKey.length())
        {
            if(answerKey[right] == 'T') t++; else f++;
            while(min(t, f) > k)
                if(answerKey[left++] == 'T') t--; else f--;
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
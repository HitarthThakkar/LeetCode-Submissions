class Solution
{
public:
    void recur(int cur, int k, int lenLeft, vector<int> &answer)
    {
        // watch out Ugly k = 0 case
        if(lenLeft == 0) { answer.push_back(cur); return; }
        int last = cur % 10;
        int digit = last + k;
        if(digit >= 0 && digit <= 9) recur(cur * 10 + digit, k, lenLeft - 1, answer);
        digit = last - k;
        if(k != 0 && digit >= 0 && digit <= 9) recur(cur * 10 + digit, k, lenLeft - 1, answer);
    }

    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> answer;
        for(int i = 1; i <= 9; i++) recur(i, k, n - 1, answer);
        return answer;
    }
};
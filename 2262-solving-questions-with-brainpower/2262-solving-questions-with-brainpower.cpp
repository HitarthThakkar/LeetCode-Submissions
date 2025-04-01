class Solution
{
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        int n = questions.size();
        vector<long long> answer(n, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            // for(auto e : answer) cout << e << " "; cout << endl;
            int val = questions[i][0];
            int limit = questions[i][1];
            if(i + limit + 1 < n) answer[i] = val + answer[i + limit + 1];
            else answer[i] = val;
            if(i + 1 < n) answer[i] = max(answer[i], answer[i + 1]);
        }
        return answer[0];
    }
};
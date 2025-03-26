class Solution
{
public:
    long long minimumRemoval(vector<int>& beans)
    {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        vector<long long int> p(n, beans[0]), s(n, beans[n - 1]);
        for(int i = 1; i < n; i++) p[i] = p[i - 1] + beans[i];
        for(int i = n - 2; i >= 0; i--) s[i] = s[i + 1] + beans[i];
        long long int answer = p[n - 1];
        for(int i = 0; i < n; i++)
        {
            long long int cur = (i - 1 >= 0 ? p[i - 1] : 0);
            cur += (s[i] - ((n - i) * 1LL * beans[i]));
            answer = min(answer, cur);
        }
        return answer;
    }
};
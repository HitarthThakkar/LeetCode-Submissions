class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0;
        int answer = 0;
        for(int ii = 1; ii < n; ii++)
        {
            if(intervals[ii][0] < intervals[i][1]) answer++;
            else i = ii;
        }
        return answer;
    }
};
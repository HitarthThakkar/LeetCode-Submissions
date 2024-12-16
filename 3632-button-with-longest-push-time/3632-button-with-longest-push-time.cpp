class Solution
{
public:
    int buttonWithLongestTime(vector<vector<int>>& events)
    {
        int prev = 0, mex = -1, mexind = -1, n = events.size();
        for(int i = 0; i < n; i++)
        {
            if((events[i][1] - prev) > mex)
            {
                mex = events[i][1] - prev;
                mexind = events[i][0];
            }
            if((events[i][1] - prev) == mex && events[i][0] < mexind)
            {
                mexind = events[i][0];
            }
            prev = events[i][1];
        }
        return mexind;
    }
};
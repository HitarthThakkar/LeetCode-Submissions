class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n = intervals.size();
        int startIndex = -1;
        int endIndex = -1;

        for(int i = 0; i < n; i++)
        {
            if(intervals[i][1] >= newInterval[0])
            {
                startIndex = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(intervals[i][0] <= newInterval[1])
            {
                endIndex = i;
                break;
            }
        }

        if(startIndex == -1)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        else if(endIndex == -1)
        {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            for(auto vec : intervals) ans.push_back(vec);
            return ans;
        }

        if(endIndex < startIndex)
        {
            vector<vector<int>> ans;

            for(int i = 0; i < n; i++)
            {
                if(i == startIndex)
                {
                    ans.push_back(newInterval);
                }
                ans.push_back(intervals[i]);
            }

            return ans;
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            if(i < startIndex || i > endIndex)
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                if(i == endIndex)
                {
                    ans.push_back(newInterval);
                }
            }
        }

        return ans;
    }
};
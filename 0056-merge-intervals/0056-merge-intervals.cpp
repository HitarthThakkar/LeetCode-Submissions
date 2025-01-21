class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int pb = intervals[0][0] , pe = intervals[0][1], i = 1;
        while(i < n)
        {
            if(intervals[i][0] <= pe)
            {
                pe = max(pe, intervals[i][1]);
            }
            else
            {
                vector<int> temp; temp.push_back(pb); temp.push_back(pe);
                ans.push_back(temp);
                pb = intervals[i][0]; pe = intervals[i][1];
            }
            i++;
        }

        vector<int> temp;
        temp.push_back(pb);
        temp.push_back(pe);
        ans.push_back(temp);

        return ans;
    }
};
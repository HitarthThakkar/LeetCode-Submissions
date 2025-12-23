class Solution
{
public:
    static bool compareFirstElement(int val, const std::vector<int>& vec) {
        return val < vec[0];
    }
    int maxTwoEvents(vector<vector<int>>& events)
    {
        int n = events.size();
        vector<vector<int>> ssEvents = events;
        sort(ssEvents.begin(), ssEvents.end());
        for(int i = n - 2; i >= 0; i--) {
            ssEvents[i][2] = max(ssEvents[i][2], ssEvents[i + 1][2]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int startAfterMe = events[i][1];
            int ind = upper_bound(ssEvents.begin(), ssEvents.end(), startAfterMe, compareFirstElement) - ssEvents.begin();
            if(ind >= n) res = max(res, events[i][2]);
            else res = max(res, events[i][2] + ssEvents[ind][2]);
        }
        return res;
    }
};
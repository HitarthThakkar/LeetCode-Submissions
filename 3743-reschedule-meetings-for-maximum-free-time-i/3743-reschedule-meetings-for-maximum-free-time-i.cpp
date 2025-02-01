class Solution {
public:
int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
{

    int n = startTime.size();
    int prevtime = 0;

    vector<int> breaks;
    breaks.push_back(0);

    for (int i = 0; i < n; i++)
    {
        int diff = startTime[i] - prevtime;

        breaks.push_back(diff);

        prevtime = endTime[i];
    }

    int diff = eventTime - prevtime;

    breaks.push_back(diff);

    k++;

    for (int i = 1; i < breaks.size(); i++)
    {
        breaks[i] += breaks[i - 1];
    }

    int ans = 0;

    for (int i = k; i < breaks.size(); i++)
    {
        ans = max(ans, breaks[i] - breaks[i - k]);
    }

    return ans;
}
};
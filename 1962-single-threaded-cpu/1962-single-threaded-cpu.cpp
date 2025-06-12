#define pai pair<int, int>
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        int n = tasks.size(); vector<pai> vp;
        for(int i = 0; i < n; i++) vp.push_back({tasks[i][0], i});
        sort(vp.begin(), vp.end());
        priority_queue<pai, vector<pai>, greater<pai>> pq;
        int i = 0; long long time = 0;
        vector<int> result;
        while(result.size() < n)
        {
            while(i < n && vp[i].first <= time)
                pq.push({tasks[vp[i].second][1], vp[i].second}), i++;
            if(pq.empty()) { time = vp[i].first; continue; }
            result.push_back(pq.top().second);
            time += pq.top().first;
            pq.pop();
        }
        return result;
    }
};
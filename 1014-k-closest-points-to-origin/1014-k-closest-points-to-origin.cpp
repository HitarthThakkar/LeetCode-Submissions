#define paip pair<int, pair<int, int>>
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<paip> pq;
        for(auto pt : points)
        {
            long long x = (1LL * pt[0]);
            long long y = (1LL * pt[1]);
            long long dist = (x * x) + (y * y);
            pq.push({dist, {x, y}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return result;
    }
};
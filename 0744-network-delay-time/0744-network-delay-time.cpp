#define pai pair<int, int>
class Solution
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pai>> adj(n + 1); // 1 based
        for(auto ele : times) adj[ele[0]].push_back({ele[1], ele[2]});
        priority_queue<pai, vector<pai>, greater<pai>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[0] = 0; // 1 based so donot consider 0.
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty())
        {
            int distance = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            for (auto nei : adj[curr_node])
            {
                int adjNode = nei.first;
                int edgeWeight = nei.second;
                if (distance + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int mex = 0;
        for(auto ele : dist) mex = max(mex, ele);
        return (mex == 1e9 ? -1 : mex);
    }
};
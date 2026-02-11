class Solution
{
public:
    int minCost(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dis(n, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        dis[0] = 0;
        pq.push({0, 0});

        while(!pq.empty())
        {
            int dtn = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n - 1) return dtn;

            for(auto nei : adj[node])
            {
                if(dis[nei.first] > dtn + nei.second)
                {
                    dis[nei.first] = dtn + nei.second;
                    pq.push({dis[nei.first], nei.first});
                }
            }
        }

        return (dis[n - 1] == 1e9 ? -1 : dis[n - 1]);
    }
};
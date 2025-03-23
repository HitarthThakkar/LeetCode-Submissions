#define pai pair<long long int, int>

class Solution
{
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        int m = 1e9 + 7;

        vector<vector<pai>> adj(n);

        for(auto e : roads)
        {
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }

        vector<long long> dis(n, 1e12);
        vector<long long> ways(n, 0);

        priority_queue<pai, vector<pai>, greater<pai>> pq;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty())
        {
            long long int dtn = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto nei : adj[node])
            {
                long long int edW = nei.first;
                int neinode = nei.second;

                if(dis[neinode] > dtn + edW)
                {
                    dis[neinode] = dtn + edW;
                    ways[neinode] = 0;
                    pq.push({dis[neinode], neinode});
                }
                if(dis[neinode] == dtn + edW)
                {
                    ways[neinode] += ways[node];
                    ways[neinode] %= m;
                }
            }
        }

        return ways[n - 1];
    }
};
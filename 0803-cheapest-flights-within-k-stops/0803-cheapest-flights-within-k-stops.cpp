#define PAIP pair<int, pair<int, int>>
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for(auto ele : flights)
        {
            int from = ele[0];
            int to = ele[1];
            int price = ele[2];
            adj[from].push_back({to, price});
        }

        queue<PAIP> q; // NOT a PQ, but a Q.
        vector<int> costance(n, 1e9); // same as distance

        // {stops, {node, costance}}
        q.push({0, {src, 0}});
        costance[src] = 0;

        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int costtn = q.front().second.second;

            if(stops > k) return (costance[dst] == 1e9 ? -1 : costance[dst]);

            q.pop();

            for(auto ele : adj[node])
            {
                int neinode = ele.first;
                int costtobeadded = ele.second;

                if(costtn + costtobeadded < costance[neinode])
                {
                    costance[neinode] = costtn + costtobeadded;
                    q.push({stops + 1, {neinode, costance[neinode]}});
                }
            }
        }

        return (costance[dst] == 1e9 ? -1 : costance[dst]);

    }
};
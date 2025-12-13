class Solution {
public:
    void dfs2(int node, int par, vector<int> &dp1, vector<int> &dp2, vector<vector<int>> &adj)
    {
        if(par == -1) dp2[node] = dp1[node];
        else dp2[node] = dp1[node] + max(0, dp2[par] - max(0, dp1[node]));

        for(auto nei : adj[node])
        {
            if(nei != par)
            {
                dfs2(nei, node, dp1, dp2, adj);
            }
        }
    }

    int dfs1(int node, int par, vector<vector<int>> &adj, vector<int> &dp1, vector<int> &good)
    {
        dp1[node] = (good[node] == 0 ? -1 : 1);
        
        for (auto nei : adj[node])
        {
            if (nei != par)
            {
                dp1[node] += max(0, dfs1(nei, node, adj, dp1, good));
            }
        }

        return dp1[node];
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>> &edges, vector<int> &good)
    {
        vector<vector<int>> adj(n);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dp1(n, 0), dp2(n, 0);

        dfs1(0, -1, adj, dp1, good);

        dfs2(0, -1, dp1, dp2, adj);

        return dp2;
    }
};
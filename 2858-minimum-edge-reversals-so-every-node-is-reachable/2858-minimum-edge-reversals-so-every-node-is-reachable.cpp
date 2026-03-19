class Solution
{
public:

    void dfs1(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int &res)
    {
        vis[node] = 1;

        for(auto nei : adj[node])
        {
            int neinode = nei.first;
            int cost = nei.second;

            if(!vis[neinode])
            {
                res += cost;
                dfs1(neinode, adj, vis, res);
            }
        }
    }

    void dfs2(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, vector<int> &answer)
    {
        vis[node] = 1;

        for(auto nei : adj[node])
        {
            int neinode = nei.first;
            int cost = nei.second;

            if(!vis[neinode])
            {
                if(cost == 1) answer[neinode] = answer[node] - 1;
                else answer[neinode] = answer[node] + 1;

                dfs2(neinode, adj, vis, answer);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> adj(n);

        for(auto e : edges)
        {
            adj[e[0]].push_back({e[1], 0});
            adj[e[1]].push_back({e[0], 1});
        }

        vector<int> vis(n, 0);
        int res = 0;

        dfs1(0, adj, vis, res);

        vector<int> answer(n);
        answer[0] = res;

        for(auto &e : vis) e = 0;

        dfs2(0, adj, vis, answer);

        return answer;
    }
};
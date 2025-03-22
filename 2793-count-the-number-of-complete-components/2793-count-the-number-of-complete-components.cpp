class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &nodes, int &edges)
    {
        vis[node] = 1;
        nodes++;
        edges += adj[node].size();
        for(auto nei : adj[node])
        {
            if(!vis[nei])
            {
                dfs(nei, adj, vis, nodes, edges);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int nodes = 0, edges = 0;
                dfs(i, adj, vis, nodes, edges);
                if(edges == (nodes * (nodes - 1))) ans++;
            }
        }
        return ans;
    }
};
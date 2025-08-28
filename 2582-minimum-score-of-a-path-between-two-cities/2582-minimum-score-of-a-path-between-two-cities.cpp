class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for(auto nei : adj[node]) {
            if(!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<vector<int>> adj(n + 1);
        for(auto e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n + 1, 0);
        dfs(1, adj, vis);
        int mini = 1e9;
        for(auto e : roads) {
            if(vis[e[0]] && vis[e[1]]) {
                mini = min(mini, e[2]);
            }
        }
        return mini;
    }
};
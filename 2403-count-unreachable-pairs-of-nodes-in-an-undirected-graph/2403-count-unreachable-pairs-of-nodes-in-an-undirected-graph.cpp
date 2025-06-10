class Solution
{
public:
    int dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1;
        int ct = 0;
        for(auto nei : adj[node])
            if(!vis[nei]) ct += dfs(nei, adj, vis);
        return 1 + ct;
    }
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(n);
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        vector<int> sizes;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                sizes.push_back(dfs(i, adj, vis));
            }
        }
        long long answer = 0;
        int nleft = n;
        for(auto sz : sizes)
        {
            nleft -= sz;
            answer += (nleft * 1LL * sz);
        }
        return answer;
    }
};
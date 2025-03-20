#define pai pair<int, int>
class Solution
{
private:
    void dfs(int node, vector<vector<pai>> &adj, vector<int> &vis, map<int, int> &group, map<int, int> &gval, int bhelu, vector<int> &mem)
    {
        vis[node] = 1;
        group[node] = bhelu;
        if(gval.find(bhelu) == gval.end())
        {
            gval[bhelu] = mem[node];
        }
        else
        {
            gval[bhelu] &= mem[node];
        }

        for(auto el : adj[node])
        {
            int nei = el.first;
            if(!vis[nei]) dfs(nei, adj, vis, group, gval, bhelu, mem);
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query)
    {
        vector<int> mem(n, -1);
        vector<vector<pai>> adj(n);

        for(auto e : edges)
        {
            int from = e[0];
            int to = e[1];
            int wei = e[2];
            if(mem[from] == -1) mem[from] = wei; else mem[from] &= wei;
            if(mem[to] == -1) mem[to] = wei; else mem[to] &= wei;
            adj[from].push_back({to, wei});
            adj[to].push_back({from, wei});
        }

        vector<int> vis(n, 0);
        map<int, int> group;
        map<int, int> gval;

        int bhelu = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, group, gval, bhelu, mem);
                bhelu++;
            }
        }

        vector<int> ans;

        for(auto q : query)
        {
            int from = q[0];
            int to = q[1];
            if(group[from] == group[to])
            {
                ans.push_back(gval[group[from]]);
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
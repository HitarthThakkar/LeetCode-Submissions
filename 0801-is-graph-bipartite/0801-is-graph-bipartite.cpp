class Solution
{
private:
    bool dfs(int node, int cta, vector<int> &col, vector<vector<int>> &adj)
    {
        col[node] = cta;
        for(auto nei : adj[node])
        {
            if(col[nei] == -1) { if(!dfs(nei, !cta, col, adj)) return false; }
            else if(col[nei] == col[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(col[i] == -1) if(!dfs(i, 0, col, graph)) return false;
        }
        return true;
    }
};
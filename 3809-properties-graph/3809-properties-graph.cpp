class Solution
{
private:
    int intersection(int i, int j, vector<vector<int>> &v)
    {
        int val = 0;
        for(int k = 0; k < 100; k++)
        {
            if(v[i][k] == v[j][k] && v[i][k] == 1)
            {
                val++;
            }
        }
        return val;
    }
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for(auto nei : adj[node])
        {
            if(!vis[nei]) dfs(nei, vis, adj);
        }
    }
public:
    int numberOfComponents(vector<vector<int>>& properties, int k)
    {
        int n = properties.size();
        vector<vector<int>> v(n, vector<int> (100, 0));

        for(int i = 0; i < n; i++)
        {
            for(auto el : properties[i])
            {
                v[i][el - 1] = 1;
            }
        }

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(intersection(i, j, v) >= k)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, vis, adj);
            }
        }

        return ans;

    }
};
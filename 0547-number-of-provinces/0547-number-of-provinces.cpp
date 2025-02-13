class Solution
{
private:
    void dfs(int ind, vector<bool> &vis, vector<vector<int>> &adj)
    {
        for(int i = 0; i < adj[ind].size(); i++)
        {
            if(adj[ind][i] == 1)
            {
                if(!vis[i])
                {
                    vis[i] = true;
                    dfs(i, vis, adj);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<bool> vis(n, false);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                ans++;
                dfs(i, vis, isConnected);
            }
        }

        return ans;
    }
};
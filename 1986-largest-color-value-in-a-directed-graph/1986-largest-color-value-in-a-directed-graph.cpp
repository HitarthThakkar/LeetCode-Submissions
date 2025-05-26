class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>>& edges)
    {
        int n = colors.length();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto nei : adj[node]) {
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if(topo.size() != n) return -1;
        vector<vector<int>> dp(n, vector<int> (26, 0));
        for(int i = n - 1; i >= 0; i--) {
            int node = topo[i];
            for(int color = 0; color < 26; color++)
                for(auto nei : adj[node])
                    dp[node][color] = max(dp[node][color], dp[nei][color]);
            dp[node][colors[node] - 'a']++;
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            for(auto e : dp[topo[i]]) res = max(res, e);
        return res;
    }
};
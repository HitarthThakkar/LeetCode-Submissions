class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        if(n == 1) return n;

        vector<vector<int>> adj(n); vector<int> inDegree(n, 0);
        vector<long long> nodeVal(values.begin(), values.end());

        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]); inDegree[e[0]]++;
            adj[e[1]].push_back(e[0]); inDegree[e[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(inDegree[i] == 1) q.push(i);

        int ans = 0;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            inDegree[curr]--;
            long long addVal = (nodeVal[curr] % k);
            if(addVal == 0) ans++;

            for(auto nei : adj[curr])
            {
                if(inDegree[nei] > 0)
                {
                    inDegree[nei]--;
                    if(inDegree[nei] == 1) q.push(nei);
                    nodeVal[nei] += addVal;
                }
            }
        }

        return ans;
    }
};
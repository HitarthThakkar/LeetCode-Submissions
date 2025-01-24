class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
        {
            for(auto node : graph[i])
            {
                adj[node].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<bool> safe(n, false);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            safe[node] = true;

            for(auto neigh : adj[node])
            {
                inDegree[neigh]--;

                if(inDegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

        vector<int> res;

        for(int i = 0; i < n; i++)
        {
            if(safe[i])
            {
                res.push_back(i);
            }
        }

        return res;
    }
};
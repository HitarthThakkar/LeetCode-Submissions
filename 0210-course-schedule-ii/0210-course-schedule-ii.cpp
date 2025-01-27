class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto ele : prerequisites)
        {
            adj[ele[1]].push_back(ele[0]);
        }

        vector<int> inDegree(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
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

        vector<int> topo;

        while(!q.empty())
        {
            int node = q.front();

            q.pop();

            topo.push_back(node);

            for(auto it : adj[node])
            {
                inDegree[it]--;

                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if(topo.size() == n)
        {
            return topo;
        }
        else
        {
            return {};
        }
    }
};
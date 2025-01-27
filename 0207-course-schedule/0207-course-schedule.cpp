class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto ele : prerequisites)
        {
            adj[ele[0]].push_back(ele[1]);
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

        int ct = 0;

        while(!q.empty())
        {
            int node = q.front();

            q.pop();

            ct++;

            for(auto it : adj[node])
            {
                inDegree[it]--;

                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return (ct == n);
    }
};
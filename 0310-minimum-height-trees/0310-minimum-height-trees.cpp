class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        /*
            See Hint 1.
            Think.
            There are ATLEAST 2 solutions to this problem.
            1)
                [OG]
                Diameter of a tree
                If diameter is odd then only that middle node is the MHT's root.
                If even then 2 middle nodes are the answer.
                Find diameter (length and end points of diameter)
                then find middle from both endpoints
            2)
                [Smart implementation]
                Toposort
                the core idea is 1st but we can do some abstract smart implementation
                the nodes which are leaf are discarded first and 
                those whose nodes who are connected to leaves have their indegree
                reduced. process continues until only 1 or 2 nodes left.  
        */

        vector<int> degree(n, 0);   // kinda like indegree
        vector<vector<int>> adj(n);

        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[1]]++;
            degree[e[0]]++;
        }

        int stillAlive = n;

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] <= 1) { q.push(i); stillAlive--; }
        }

        while(stillAlive > 0)
        {
            int sz = q.size();

            for(int i = 0; i < sz; i++)
            {
                int curNode = q.front();
                q.pop();

                for(auto &nei : adj[curNode])
                {
                    degree[nei]--;
                    if(degree[nei] == 1) { q.push(nei); stillAlive--; }
                }
            }
        }

        vector<int> result;
        while(!q.empty()) { result.push_back(q.front()); q.pop(); }
        return result;
    }
};
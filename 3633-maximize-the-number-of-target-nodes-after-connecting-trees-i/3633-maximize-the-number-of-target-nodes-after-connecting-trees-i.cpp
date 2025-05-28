class Solution
{
public:
    int recur(int node, int parent, int left, vector<vector<int>> &adj)
    {
        if(left == 0) return 1;
        int answer = 1;
        for(auto nei : adj[node])
            if(nei != parent)
                answer += recur(nei, node, left - 1, adj);
        return answer;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for(auto e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(auto e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        int mex = 0;
        if(k > 0)
            for(int i = 0; i < m; i++)
                mex = max(mex, recur(i, -1, k - 1, adj2));
        vector<int> result;
        for(int i = 0; i < n; i++)
            result.push_back(recur(i, -1, k, adj1) + mex);
        return result;
    }
};
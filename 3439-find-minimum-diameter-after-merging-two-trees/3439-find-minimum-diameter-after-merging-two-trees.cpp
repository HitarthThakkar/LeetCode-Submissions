class Solution
{
public:
    pair<int, int> recur(int node, int parent, vector<vector<int>> &adj)
    {
        int depth = -1;
        int res = -1;
        for(auto nei : adj[node])
        {
            if(nei != parent)
            {
                pair<int, int> pai = recur(nei, node, adj);
                if(depth < pai.first)
                {
                    depth = pai.first;
                    res = pai.second;
                }
            }
        }
        if(depth == -1) return {0, node};
        return {depth + 1, res};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
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

        pair<int, int> a = recur(0, -1, adj1);
        pair<int, int> b = recur(0, -1, adj2);
        pair<int, int> c = recur(a.second, -1, adj1);
        pair<int, int> d = recur(b.second, -1, adj2);

        int one = c.first;
        int two = d.first;

        if(one & 1) one++;
        if(two & 1) two++;

        one /= 2;
        two /= 2;

        int gokbam = max(c.first, d.first);

        return max(one + two + 1, gokbam);
    }
};
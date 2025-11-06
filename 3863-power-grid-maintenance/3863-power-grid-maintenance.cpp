class DSU
{
private:
    vector<int> rank, parent;
    int n;

public:
    DSU(int size)
    {
        int n = size + 1;
        rank.resize(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    // Doing with path compression, as it makes things faster.
    int findUltimateParent(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    // We can do unionBySize also, both are fine for this question, because it doesn't matter.
    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] == rank[ulp_v])
        {
            rank[ulp_u]++;
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
        }
    }
};

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {

        DSU* dsu = new DSU(c);

        for(auto edge : connections)
        {
            dsu->unionByRank(edge[0], edge[1]);
        }

        map<int, set<int>> mp;

        for(int i = 1; i <= c; i++)
        {
            int ulpar = dsu->findUltimateParent(i);
            mp[ulpar].insert(i);
        }

        vector<int> result;

        for(auto q : queries)
        {
            if(q[0] == 1)
            {
                int ulpar = dsu->findUltimateParent(q[1]);

                if(mp[ulpar].find(q[1]) == mp[ulpar].end())
                {
                    if(mp[ulpar].size() == 0)
                    {
                        result.push_back(-1);
                    }
                    else
                    {
                        result.push_back(*mp[ulpar].begin());
                    }
                }
                else
                {
                    result.push_back(q[1]);
                }
            }
            else
            {
                int ulpar = dsu->findUltimateParent(q[1]);
                mp[ulpar].erase(q[1]);
            }
        }

        return result;
    }
};
class DSU
{
    vector<int> rank, parent;
public:

    DSU(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUP(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUP(parent[node]);
    }

    void unite(int u, int v)
    {
        int ulp_u = findUP(u);
        int ulp_v = findUP(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:

    bool validate(vector<vector<int>> &lcp)
    {
        int n = lcp.size();

        // mirrored check
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) if(lcp[i][j] != lcp[j][i]) return false;

        // main diag check
        int ct = n;
        for(int i = 0; i < n; i++) if(lcp[i][i] != ct) return false; else ct--;

        // other trailing check
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(lcp[i][j] > 0)
                {
                    int ct = lcp[i][j];
                    int ii = i;
                    int jj = j;

                    while(ii < n && jj < n && lcp[ii][jj] != 1)
                    {
                        if(lcp[ii][jj] != ct) return false;
                        ii++, jj++, ct--;
                    }

                    if(ii >= n || jj >= n) return false;
                    ii++, jj++;
                    if(ii < n && jj < n) {
                        if(lcp[ii][jj] != 0) return false;
                    }
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp)
    {
        int n = lcp.size();
        bool valid = validate(lcp);
        if(!valid) return "";

        DSU myds(n);
        vector<pair<int, int>> enemy;

        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
            if(lcp[i][j] != 0) myds.unite(i, j);
            else enemy.push_back({i, j});
        }

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            int root = myds.findUP(i);
            mp[root].push_back(i);
        }

        if(mp.size() > 26) return "";

        for(auto pr : enemy) {
            if(myds.findUP(pr.first) == myds.findUP(pr.second)) return "";
        }

        map<int, vector<int>> groups;

        for(auto &e : mp) {
            int sardar = *min_element(e.second.begin(), e.second.end());
            for(auto ee : e.second) groups[sardar].push_back(ee);
        }

        char c = 'a';
        string res(n, c);

        for(auto &g : groups) {
            for(auto &e : g.second) res[e] = c;
            c++;
        }

        return res;
    }
};
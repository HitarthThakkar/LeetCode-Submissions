class DSU
{
private:
    vector<int> size, parent;
    int sz;

public:

    DSU(int n)
    {
        sz = n;
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i, size[i] = 1;
    }

    int findUltimateParent(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = findUltimateParent(parent[a]);
    }

    int getSize(int a)
    {
        return size[a];
    }

    bool inSameComponent(int a, int b)
    {
        return (findUltimateParent(a) == findUltimateParent(b));
    }

    void Union(int a, int b)
    {
        if(inSameComponent(a, b)) return;
        
        int p1 = findUltimateParent(a);
        int p2 = findUltimateParent(b);
        
        if(size[p1] >= size[p2])
        {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else
        {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }
};

class Solution
{
private:
    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxSize = 1;

        DSU mydsu(n * m);

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(isValid(nr, nc, m, n) && grid[nr][nc] == 1)
                        {
                            int v1 = (i * n) + j;
                            int v2 = (nr * n) + nc;
                            mydsu.Union(v1, v2);
                            int parent = mydsu.findUltimateParent(v2);
                            int size = mydsu.getSize(parent);
                            maxSize = max(size, maxSize);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0)
                {
                    int size = 1;
                    set<int> vis;

                    for(int k = 0; k < 4; k++)
                    {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(isValid(nr, nc, m, n) && grid[nr][nc] == 1)
                        {
                            int v2 = (nr * n) + nc;
                            int parent = mydsu.findUltimateParent(v2);

                            if(vis.find(parent) == vis.end())
                            {
                                size += mydsu.getSize(parent);
                                vis.insert(parent);
                            }
                        }
                    }

                    maxSize = max(size, maxSize);
                }
            }
        }
        return maxSize;
    }
};
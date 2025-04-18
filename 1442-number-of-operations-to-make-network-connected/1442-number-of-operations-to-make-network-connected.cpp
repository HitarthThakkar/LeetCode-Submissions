class DSU
{
private:
    vector<int> size, parent;

public:

    DSU(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i, size[i] = 1;
    }

    int findUltimateParent(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = findUltimateParent(parent[a]);
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

        if(size[p1] > size[p2])
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

    int countComponents()
    {
        int ct = 0, i = 0;
        for(auto e : parent)
        {
            ct += (e == i);
            i++;
        }
        return ct;
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        DSU mydsu(n);
        int spare = 0;
        for(auto v : connections)
        {
            if(mydsu.inSameComponent(v[0], v[1])) spare++;
            else mydsu.Union(v[0], v[1]);
        }
        int components = mydsu.countComponents();
        return ((spare >= (components - 1)) ? (components - 1) : -1);
    }
};
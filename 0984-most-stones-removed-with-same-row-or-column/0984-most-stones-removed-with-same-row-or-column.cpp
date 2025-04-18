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

    int answer()
    {
        int answer = 0;
        for(int i = 0; i < sz; i++)
        {
            if(i == parent[i])
            {
                int sz = size[i];
                answer += (sz - 1);
            }
        }
        return answer;
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        DSU mydsu(n);

        map<pair<int, int>, int> m;
        for(int i = 0; i < n; i++) m[{stones[i][0], stones[i][1]}] = i;

        map<int, vector<int>> row, col;

        for(int i = 0; i < n; i++)
        {
            int r = stones[i][0];
            int c = stones[i][1];

            for(auto nc : row[r])
            {
                int val = m[{r, nc}];
                mydsu.Union(i, val);
            }
            for(auto nr : col[c])
            {
                int val = m[{nr, c}];
                mydsu.Union(i, val);
            }

            row[r].push_back(c);
            col[c].push_back(r);
        }

        return mydsu.answer();
    }
};
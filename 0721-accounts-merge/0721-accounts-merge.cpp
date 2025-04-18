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

    vector<int> giveParentList()
    {
        vector<int> res;
        for(int i = 0; i < sz; i++) if(i == parent[i]) res.push_back(i);
        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        int n = accounts.size();
        DSU mydsu(n);

        map<string, int> ati;   // account to index
        map<int, int> itci;     // index to compressed (merged) index

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(ati.find(accounts[i][j]) == ati.end())
                {
                    ati[accounts[i][j]] = i;
                }
                else
                {
                    int pi = ati[accounts[i][j]];
                    mydsu.Union(pi, i);
                }
            }
        }

        vector<int> parents = mydsu.giveParentList();
        vector<vector<string>> answer(parents.size());

        int i = 0;

        for(auto p : parents)
        {
            itci[p] = i;
            answer[i].push_back(accounts[p][0]);
            i++;
        }

        for(auto e : ati)
        {
            int parent = mydsu.findUltimateParent(e.second);
            int ci = itci[parent];
            answer[ci].push_back(e.first);
        }

        return answer;
    }
};
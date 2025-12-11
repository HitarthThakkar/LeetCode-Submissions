class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings)
    {
        vector<int> u(n + 1, 1e6), d(n + 1, -1), l(n + 1, 1e6), r(n + 1, -1);
        for(auto e : buildings)
        {
            u[e[0]] = min(u[e[0]], e[1]);
            d[e[0]] = max(d[e[0]], e[1]);

            l[e[1]] = min(l[e[1]], e[0]);
            r[e[1]] = max(r[e[1]], e[0]);
        }

        int ct = 0;

        for(auto e : buildings)
        {
            if(u[e[0]] < e[1] && d[e[0]] > e[1] && l[e[1]] < e[0] && r[e[1]] > e[0]) ct++;
        }

        return ct;
    }
};
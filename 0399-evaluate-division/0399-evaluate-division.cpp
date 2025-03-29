class Solution
{
private:
    double findMyVal(string departure, string destination, map<string, vector<pair<string, double>>> &adj, set<string> &vis)
    {
        queue<pair<string, double>> q;
        q.push({departure, 1.0});
        vis.insert(departure);

        while(!q.empty())
        {
            string cur = q.front().first;
            double valtn = q.front().second;
            q.pop();
            for(auto neighbours : adj[cur])
            {
                string neiname = neighbours.first;
                double value = neighbours.second;

                if(neiname == destination)
                {
                    return (valtn * value);
                }

                if(vis.find(neiname) == vis.end())
                {
                    q.push({neiname, valtn * value});
                    vis.insert(neiname);
                }
            }
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int n = equations.size();
        map<string, vector<pair<string, double>>> adj;
        vector<double> result;
        for(int i = 0; i < n; i++)
        {
            string from = equations[i][0];
            string to = equations[i][1];
            double cost = values[i];
            adj[from].push_back({to, cost});
            cost = (1.0 / cost);
            adj[to].push_back({from, cost});
        }
        for(auto q : queries)
        {
            string from = q[0];
            string to = q[1];
            if(adj.find(from) == adj.end() || adj.find(to) == adj.end()) result.push_back(-1.0);
            else if(from == to) result.push_back(1.0);
            else {
            set<string> vis;
            double myVal = findMyVal(from, to, adj, vis);
            result.push_back(myVal);
            }
        }
        return result;
    }
};
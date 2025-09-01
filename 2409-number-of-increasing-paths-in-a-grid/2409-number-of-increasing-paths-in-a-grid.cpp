class Solution
{
public:
    int countPaths(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1000000007;

        map<int, vector<int>> adj;
        map<int, vector<int>> inverse_adj;
        map<int, int> indegree;
        queue<int> q;
        int sum = 0;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int id = (n * i) + j;

                for(int k = 0; k < 4; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] < grid[i][j])
                    {
                        int pid = (n * nr) + nc;
                        adj[id].push_back(pid);
                        inverse_adj[pid].push_back(id);
                    }
                }

                indegree[id] = adj[id].size();

                if(adj[id].size() == 0) q.push(id);
            }
        }

        // for(auto e : adj) {
        //     cout << e.first << " -> ";
        //     for(auto ee : e.second) {
        //         cout << ee << " ";
        //     }
        //     cout << endl;
        // }
        //     cout << endl;
        //     cout << endl;

        while(!q.empty())
        {
            int id = q.front();
            q.pop();

            int allfatherscontributions = 0;

            for(auto fathers : adj[id])
            {
                allfatherscontributions = ((allfatherscontributions % mod) + 
                                                (adj[fathers].back() % mod)) % mod;
            }

            adj[id].push_back(allfatherscontributions + 1);
            // cout << adj[id].back() << endl;

            for(auto child : inverse_adj[id])
            {
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }

            sum = (((sum % mod) + (adj[id].back() % mod)) % mod);
            // cout << sum << endl;
        }

        return sum;
    }
};
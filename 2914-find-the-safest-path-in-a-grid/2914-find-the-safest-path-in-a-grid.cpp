class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // minimum pq, having all 1's positions and 0 as the safeness factor
        // we mark the minimum safeness factor for each cell in grid using this pq traversal

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        auto cmp = [] (pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
        {
            return a.first > b.first;
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq;

        vector<vector<int>> safeness(n, vector<int> (n, 1e9));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    pq.push({0, {i, j}});
                    safeness[i][j] = 0;
                }
            }
        }

        while(!pq.empty())
        {
            int sf = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && safeness[nr][nc] > sf + 1)
                {
                    safeness[nr][nc] = sf + 1;
                    pq.push({sf + 1, {nr, nc}});
                }
            }
        }

        // for(auto v : safeness) { for(auto e : v) cout << e << " "; cout << endl; }

        // return -1;

        // now we have a safeness array, which shows the safeness of a cell in O(1)
        // so now our task reduces to finding the path in which the minimum safeness factor is maximum

        vector<vector<int>> path_safeness(n, vector<int> (n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq2;

        path_safeness[0][0] = safeness[0][0];
        // cout << path_safeness[0][0] << endl;
        pq2.push({path_safeness[0][0], {0, 0}});

        while(!pq2.empty())
        {
            int sf = pq2.top().first;
            int r = pq2.top().second.first;
            int c = pq2.top().second.second;

            // cout << sf << " " << r << " " << c << endl;

            pq2.pop();

            if(sf == 0) break;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && path_safeness[nr][nc] < min(sf, safeness[nr][nc]))
                {
                    path_safeness[nr][nc] = min(sf, safeness[nr][nc]);
                    pq2.push({path_safeness[nr][nc], {nr, nc}});
                }
            }
        }


        return path_safeness[n - 1][n - 1];
    }
};
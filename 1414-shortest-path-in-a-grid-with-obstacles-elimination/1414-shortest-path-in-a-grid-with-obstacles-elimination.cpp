// class Solution {
// public:
//     int shortestPath(vector<vector<int>>& grid, int k) {
        
//     }
// };

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {

public:

	int shortestPath(vector<vector<int>> &grid, int k)
	{
		int m = grid.size();
		int n = grid[0].size();

		auto cmp = [](const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
        {
            return a.first > b.first;
        };

		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> pq;	// {steps, {left_k, r, c}}
		unordered_map<pair<int, int>, pair<int, int>, pair_hash> vis;				                                    // {{r,c}, {s, k}}

		vector<int> start_state = {k, 0, 0};
		pq.push({0, start_state});
		vis[{0, 0}] = {0, k};

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

		while(!pq.empty())
		{
			int steps = pq.top().first;
			int left_k = pq.top().second[0];
            int r = pq.top().second[1];
            int c = pq.top().second[2];

            // cout << steps << " " << left_k << " " << r << " " << c << endl;

            pq.pop();

            if(r == m - 1 && c == n - 1) return steps;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n)
                {
                    int prev_steps = 1e5;
                    int prev_k = -1;

                    if(vis.find({nr, nc}) != vis.end())
                    {
                        prev_steps = vis[{nr, nc}].first;
                        prev_k = vis[{nr, nc}].second;
                    }

                    if(grid[nr][nc] == 1)
                    {
                        if(left_k > 0 && (left_k - 1 > prev_k) )
                        {
                            pq.push({steps + 1, {left_k - 1, nr, nc}});
                            vis[{nr, nc}] = {steps + 1, left_k - 1};
                        }
                    }
                    else
                    {
                        if((left_k > prev_k))
                        {
                            pq.push({steps + 1, {left_k, nr, nc}});
                            vis[{nr, nc}] = {steps + 1, left_k};
                        }
                    }
                }
            }
        }

        return -1;
    }
};
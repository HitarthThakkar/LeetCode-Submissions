class Solution
{
public:
    int minCost(vector<vector<int>>& grid)
    {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int nr = grid.size(), nc = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> minCost(nr, vector<int> (nc, INT_MAX));
        minCost[0][0] = 0;
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int cost = cur[0], row = cur[1], col = cur[2];

            if(minCost[row][col] < cost) continue;

            for(int dir = 0; dir < 4; dir++)
            {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                if(newRow >= 0 && newRow < nr && newCol >= 0 && newCol < nc)
                {
                    int newCost = cost + ((dir != (grid[row][col] - 1)) ? 1 : 0);

                    if(minCost[newRow][newCol] > newCost)
                    {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[nr - 1][nc - 1];
    }
};
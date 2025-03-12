#define PAIP pair<int, pair<int, int>>
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> eff(m, vector<int> (n, 1e8));
        priority_queue<PAIP, vector<PAIP>, greater<PAIP>> pq;

        pq.push({0,{0, 0}});
        eff[0][0] = 0;

        while(!pq.empty())
        {
            int etn = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n)
                {
                    int etr = abs(heights[r][c] - heights[nr][nc]);
                    if(max(etn, etr) < eff[nr][nc])
                    {
                        eff[nr][nc] = max(etn, etr);
                        pq.push({max(etn, etr), {nr, nc}});
                    }
                }
            }
        }

        return eff[m - 1][n - 1];
    }
};
#define paip pair<int, pair<int, int>>

class Solution
{
public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        priority_queue<paip, vector<paip>, greater<paip>> pq;

        vis[0][0] = 1;
        pq.push({0, {0, 0}});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!pq.empty())
        {
            int dtn = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;

            pq.pop();

            if(r == n - 1 && c == m - 1)
            {
                return dtn;
            }

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    pq.push({max(dtn, moveTime[nr][nc]) + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
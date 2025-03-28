#define pai pair<int, int>
#define paip pair<int, pair<int, int>>
class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        int m = grid.size();
        int n = grid[0].size();
        int q = queries.size();
        vector<pai> qcp; int i = 0;
        for(auto qu : queries) qcp.push_back({qu, i}), i++;
        sort(qcp.begin(), qcp.end());
        vector<int> result(q, 0);
        int ptr = 0, sum = 0;
        priority_queue<paip, vector<paip>, greater<paip>> pq;
        while(ptr < q && qcp[ptr].first <= grid[0][0]) ptr++;
        if(ptr == q) return result;
        else { pq.push({grid[0][0], {0, 0}}); grid[0][0] = -1; }
        while(!pq.empty())
        {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            while(ptr < q && qcp[ptr].first <= val) result[qcp[ptr].second] = sum, ptr++;
            if(ptr == q) return result;
            sum++;
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] != -1)
                {
                    pq.push({grid[nr][nc], {nr, nc}});
                    grid[nr][nc] = -1;
                }
            }
        }
        while(ptr < q) result[qcp[ptr].second] = sum, ptr++;
        return result;
    }
};
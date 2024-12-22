class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries)
    {
        int n = heights.size();
        int m = queries.size();
        vector<int> res(m, -1);
        map<int, vector<pair<int, int>>> mp;

        for(int i = 0; i < m; i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            if(a > b) swap(a, b);
            if(a == b || heights[a] < heights[b]) res[i] = b;
            else mp[b].push_back({heights[a], i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < n; i++)
        {
            if(mp.find(i) != mp.end()) for(auto ele : mp[i]) pq.push(ele);
            while(!pq.empty() && heights[i] > pq.top().first)
            {
                res[pq.top().second] = i;
                pq.pop();
            }
        }

        return res;
    }
};
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        int INF = 1e8;
        vector<int> v(n, INF);  // INF means no constraint at start

        queue<int> q;
        v[0] = 0; q.push(0);    // new constraint (restriction)
        for(auto e : restrictions) { v[e[0]] = e[1]; q.push(e[0]); }

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(i > 0) {
                int constraint = v[i] + diff[i - 1];
                if(v[i - 1] > constraint) { v[i - 1] = constraint; q.push(i - 1); }
            }

            if(i < n - 1) {
                int constraint = v[i] + diff[i];
                if(v[i + 1] > constraint) { v[i + 1] = constraint; q.push(i + 1); }
            }
        }
        
        return *max_element(v.begin(), v.end());
    }
};
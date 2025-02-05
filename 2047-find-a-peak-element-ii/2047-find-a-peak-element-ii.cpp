class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat)
    {
        // Ofc not better than BS soln in worst case.
        int m = mat.size(); int n = mat[0].size();
        int r = 0, c = 0;
        vector<int> dr = {-1, 1, 0, 0}; vector<int> dc = {0, 0, -1, 1};
        while(true) {
            int mex = mat[r][c]; int nrr = r, ncc = c;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i]; int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && mat[nr][nc] > mex) {
                    mex = mat[nr][nc];
                    nrr = nr, ncc = nc;
                }
            }
            if(mex == mat[r][c]) return {r, c}; else r = nrr, c = ncc;
        }
        return {};
    }
};
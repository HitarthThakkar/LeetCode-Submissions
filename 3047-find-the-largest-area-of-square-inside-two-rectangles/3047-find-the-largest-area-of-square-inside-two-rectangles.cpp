class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long mexsz = 0;
        for (int i = 0; i < n; i++) {
            int blix = bottomLeft[i][0];
            int bliy = bottomLeft[i][1];
            int trix = topRight[i][0];
            int triy = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int bljx = bottomLeft[j][0];
                int bljy = bottomLeft[j][1];
                int trjx = topRight[j][0];
                int trjy = topRight[j][1];
                if ((bljx < trix) && (blix < trjx) && (bliy < trjy) && (bljy < triy)) {
                    int len = min(trix, trjx) - max(blix, bljx);
                    int brth = min(triy, trjy) - max(bliy, bljy);
                    long long sz = min(len, brth);
                    mexsz = max(mexsz, sz * sz);
                }
            }
        }
        return mexsz;
    }
};
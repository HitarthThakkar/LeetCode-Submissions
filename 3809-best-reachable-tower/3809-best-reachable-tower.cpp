class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int bx = 1e9;
        int by = 1e9;
        int bqf = -1;

        for(auto e : towers)
            {
                int dis = abs(center[0] - e[0]) + abs(center[1] - e[1]);

                if(dis <= radius)
                {
                    if(bqf < e[2])
                    {
                        bx = e[0], by = e[1], bqf = e[2];
                    }
                    else if(bqf == e[2])
                    {
                        if(bx > e[0] || (bx == e[0] && by > e[1]))
                        {
                            bx = e[0], by = e[1], bqf = e[2];                            
                        }
                    }
                }
            }

        if(bx == 1e9 && by == 1e9) return {-1, -1};
        return {bx, by};
    }
};
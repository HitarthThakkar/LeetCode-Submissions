class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        // tower is declared as 100 x 100 for implementation simplicity, but it's actually pyramid.
        // we store the value of 'flow-through' fluid for each glass in the pyramid tower.
        vector<vector<double>> pyramid_tower(100, vector<double> (100, 0));

        // all the 'poured' glasses will always flow-through the base glass. 
        pyramid_tower[0][0] = (double) poured;

        for(int r = 0; r <= query_row; r++)
        {
            for(int c = 0; c <= r; c++)
            {
                // we assume that the value of
                // flow-through liquid for the glass at (r, c) is already calculated in previous iterations.

                double my_flow_through = pyramid_tower[r][c];

                // Parent glass itself is not full so it can't give anything to children
                if(my_flow_through <= 1.00) continue;

                // so now from it's own already calculated flow-through value,
                // we calculate it's left child's flow-through and right child's flow-through if child exists.

                if(r != 99) pyramid_tower[r + 1][c] += (my_flow_through - 1.0) / 2.0;    // takes 1 glass for himself and half for right
                if(r != 99) pyramid_tower[r + 1][c + 1] += (my_flow_through - 1.0) / 2.0;    // 1 glass for himself and half for left
            }
        }

        return min(1.0, pyramid_tower[query_row][query_glass]);
    }
};
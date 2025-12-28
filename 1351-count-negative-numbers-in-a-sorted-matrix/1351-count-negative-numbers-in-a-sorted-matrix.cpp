class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i = 0;
        int j = m - 1;

        int ct = 0;

        while(i < n) {

            // first the forget line 20 and understand the whole algorithm without it.
            // after understanding the algo, come to line 20 and guess why it's there.
            // It fixes the "all positives" case, like sample case 2.
            // comment line 20 and watch code get RE on sample case 2.
            if(j == m) j--;

            while(j >= 0 && grid[i][j] < 0) j--;
            j++;
            ct += (m - j);
            i++;
        }

        return ct;
    }
};
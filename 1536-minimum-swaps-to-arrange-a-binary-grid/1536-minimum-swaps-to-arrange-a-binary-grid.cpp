class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        //count of zeros from right to left until any one (1) is occured
        vector<int> zeroCount(n,0);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > 0 && grid[i][j] == 0; j--){
                zeroCount[i]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            // find the nearest index which has at least n-1-i zeros
            while(j < n && zeroCount[j] < n-i-1){
                j++;
            }
            if(j == n) return -1;
            ans += j-i;
            // perform swaps and bring the row at index j to index i
            while(j > i){
                swap(zeroCount[j], zeroCount[j-1]);
                j--;
            }
        }

        return ans;
    }
};
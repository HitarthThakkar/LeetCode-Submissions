class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0, c = n - 1;
        // why r = 0 and c = n - 1 ?
        // cuz 15 ani row ma sauthi moto che & col ma sauthi nano che
        // aa property bija koi element pase nathi and aa j property useful che.
        while(r < m && c >= 0) {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) c--;
            else r++;
            /*
                1) aa col ma sauthi nano hu j chu bija marathi mota che
                    so aa col ma `target` nathi fr.
                2) aa row ma sauthi moto hu j chu bija marathi nana che
                    so aa row ma `target` nathi fr fr.
            */
        }
        return false;
    }
};
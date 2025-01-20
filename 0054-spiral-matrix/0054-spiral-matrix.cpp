class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int a = n, b = m - 1;
        int gi = 0, gj = -1;
        while(true)
        {
            if(a > 0) {
                gj++;
                for(int i=0; i<a; i++) res.push_back(matrix[gi][gj]), gj++; a--; gj--;
            }
            else return res;
            if(b > 0) {
                gi++;
                for(int i=0; i<b; i++) res.push_back(matrix[gi][gj]), gi++; b--; gi--;
            }
            else return res;
            if(a > 0) {
                gj--;
                for(int i=0; i<a; i++) res.push_back(matrix[gi][gj]), gj--; a--; gj++;
            }
            else return res;
            if(b > 0) {
                gi--;
                for(int i=0; i<b; i++) res.push_back(matrix[gi][gj]), gi--; b--; gi++;
            }
            else return res;
        }
        return res;
    }
};
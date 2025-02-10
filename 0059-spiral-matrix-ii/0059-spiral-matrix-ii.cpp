class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int> (n, -1));
        int i=0,j=0,sqsz=n,val=1;
        while(val <= (n * n)) {
            int k=sqsz;while(val<=(n*n)&&k--)mat[i][j]=val++,j++;j--;i++;
            k=sqsz-1;while(val<=(n*n)&&k--)mat[i][j]=val++,i++;i--;j--;
            k=sqsz-1;while(val<=(n*n)&&k--)mat[i][j]=val++,j--;j++;i--;
            k=sqsz-2;while(val<=(n*n)&&k--)mat[i][j]=val++,i--;i++;j++;
            sqsz-=2;
        }
        return mat;
    }
};
class Solution
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        map<int, int> mp; int i = 0;
        for(auto ele : arr) mp[ele] = i, i++;
        int ans = arr.size() - 1;
        for(int i = 0; i < mat.size(); i++)
        {
            int localmaxi = -1;
            for(int j = 0; j < mat[i].size(); j++)
            {
                localmaxi = max(localmaxi, mp[mat[i][j]]);
            }
            ans = min(ans, localmaxi);
        }
        for(int i = 0; i < mat[0].size(); i++)
        {
            int localmaxi = -1;
            for(int j = 0; j < mat.size(); j++)
            {
                localmaxi = max(localmaxi, mp[mat[j][i]]);
            }
            ans = min(ans, localmaxi);
        }
        return ans;
    }
};
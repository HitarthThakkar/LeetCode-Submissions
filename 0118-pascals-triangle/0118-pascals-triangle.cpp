class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        int sz = 1;
        while(sz <= numRows) {
            vector<int> temp(sz, 1); ans.push_back(temp); sz++;
        }

        for(int i = 2; i < ans.size(); i++)
        {
            for(int j = 1; j < ans[i].size() - 1; j++)
            {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};
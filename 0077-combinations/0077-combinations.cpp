class Solution
{
public:
    void recur(int i, int n, vector<int> &temp, vector<vector<int>> &result)
    {
        if(i == temp.size())
        {
            result.push_back(temp);
            return;
        }
        int start = 1;
        if(i > 0) start = temp[i - 1] + 1;
        for(int j = start; j <= n; j++)
        {
            temp[i] = j;
            recur(i + 1, n, temp, result);
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> temp(k);
        recur(0, n, temp, result);
        return result;
    }
};
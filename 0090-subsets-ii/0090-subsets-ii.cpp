class Solution
{
public:
    void recur(int i, int n, vector<int> &v, vector<int> &temp, vector<vector<int>> &res)
    {
        if(i == n)
        {
            res.push_back(temp);
            return;
        }
        
        // not take
        int ni = i;
        while(ni < n && v[ni] == v[i]) ni++;
        recur(ni, n, v, temp, res);

        // take
        temp.push_back(v[i]);
        recur(i + 1, n, v, temp, res);

        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        recur(0, n, nums, temp, res);
        return res;
    }
};
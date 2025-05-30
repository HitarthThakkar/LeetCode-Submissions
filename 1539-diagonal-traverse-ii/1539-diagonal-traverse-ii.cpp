class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        // CRUX : Why TLE in prev submission ?

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> result;

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            result.push_back(nums[r][c]);

            // there's a row below this one
            if(c == 0 && r + 1 < nums.size()) q.push({r + 1, c});
            // there's still a cell in right side of this one
            if(c + 1 < nums[r].size()) q.push({r, c + 1});
        }

        return result;
    }
};
class Solution
{
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size(), q = queries.size(), mark = 0;
        vector<int> marker(n, -1); vector<bool> answer(q, false);

        for(int i = 0; i < n - 1; i++)
            if((nums[i] & 1) ^ (nums[i + 1] & 1))
                marker[i] = marker[i + 1] = mark;
            else
                marker[i] = mark, mark++, marker[i + 1] = mark;

        for(int i = 0; i < q; i++)
            answer[i] = (marker[queries[i][0]] == marker[queries[i][1]]);

        return answer;
    }
};
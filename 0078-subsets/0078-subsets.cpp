class Solution
{
private:
    void recur(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &answer)
    {
        if(ind == nums.size())
        {
            answer.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        recur(ind + 1, nums, temp, answer);
        temp.pop_back();
        recur(ind + 1, nums, temp, answer);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> answer;
        vector<int> temp;
        recur(0, nums, temp, answer);
        return answer;
    }
};
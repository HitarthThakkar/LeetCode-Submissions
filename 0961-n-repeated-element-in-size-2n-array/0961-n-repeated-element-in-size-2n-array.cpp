class Solution
{
public:
    int repeatedNTimes(vector<int>& nums)
    {
        unordered_set<int> vis;
        while(true)
        {
            int rand_index = rand() % nums.size();
            if(vis.find(nums[rand_index]) != vis.end()) return nums[rand_index];
            else vis.insert(nums[rand_index]);
            nums[rand_index] = nums.back();
            nums.pop_back();
        }
        return -1;
    }
};
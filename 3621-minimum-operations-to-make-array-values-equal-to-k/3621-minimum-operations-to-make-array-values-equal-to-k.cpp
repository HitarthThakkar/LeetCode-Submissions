class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        int mini = *min_element(nums.begin(), nums.end());
        if(k > mini) return -1;
        unordered_set<int> s;
        for(auto e : nums) s.insert(e);
        int uec = s.size();
        if(k == mini) return (uec - 1);
        else return uec;
    }
};
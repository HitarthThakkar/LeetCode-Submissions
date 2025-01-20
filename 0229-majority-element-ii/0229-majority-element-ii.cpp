class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int c1 = 0, c2 = 0, ele1 = INT_MIN, ele2 = INT_MIN, mini = nums.size() / 3;
        for(int i = 0; i < nums.size(); i++)
        {
            if(c1 == 0 && ele2 != nums[i]) c1++, ele1 = nums[i];
            else if(c2 == 0 && ele1 != nums[i]) c2++, ele2 = nums[i];
            else if(ele1 == nums[i]) c1++;
            else if(ele2 == nums[i]) c2++;
            else c1--, c2--;
        }
        c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++)
            if(ele1 == nums[i]) c1++; else if(ele2 == nums[i]) c2++;
        vector<int> v; if(c1 > mini) v.push_back(ele1); if(c2 > mini) v.push_back(ele2);
        return v;
    }
};
class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int count1 = 0, count2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count1 == 0 && ele2 != nums[i])
            {
                count1++;
                ele1 = nums[i];
            }
            else if(count2 == 0 && ele1 != nums[i])
            {
                count2++;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])
            {
                count1++;
            }
            else if(ele2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(ele1 == nums[i])
            {
                c1++;
            }
            if(ele2 == nums[i])
            {
                c2++;
            }
        }

        vector<int> v;
        int mini = nums.size() / 3;

        if(c1 > mini)
        {
            v.push_back(ele1);
        }
        if(c2 > mini)
        {
            v.push_back(ele2);
        }

        return v;
    }
};
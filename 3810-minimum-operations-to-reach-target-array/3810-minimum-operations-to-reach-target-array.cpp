class Solution
{
public:
    int minOperations(vector<int>& nums, vector<int>& target)
    {
        int l = 0;
        int r = 1;
        int n = nums.size();
        int ops = 0;

        unordered_set<int> cured;

        while(r < n)
        {
            if(nums[r] == nums[l])
            {
                r++;
                continue;
            }
            else
            {
                bool bad = false;
                
                for(int i = l; i < r; i++)
                {
                    if(cured.find(nums[i]) == cured.end() && nums[i] != target[i])
                    {
                        bad = true;
                        break;
                    }
                }

                if(bad) {
                    ops++;
                    for(int i = l; i < r; i++) cured.insert(nums[i]);
                }

                l = r;
                r++;
            }
        }

        bool bad = false;
        
        for(int i = l; i < r; i++)
        {
            if(cured.find(nums[i]) == cured.end() && nums[i] != target[i])
            {
                bad = true;
                break;
            }
        }

        if(bad) ops++;

        return ops;
    }
};
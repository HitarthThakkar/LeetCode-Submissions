class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // 2025 Hiring Prep Sprint Q3 [mid, somewhat thinking heavy]
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int preva = -1e6;

        vector<vector<int>> res;

        for(int i = 0; i < n - 2; i++)
        {

            // Unique thing condition
            if(nums[i] != preva)
            {

                int lo = i + 1;
                int hi = n - 1;

                int target = (-1 * (nums[i]));

                int pb = nums[lo]; // previous val of 'b', similar unique thing condition
                int pc = nums[hi]; // previous val of 'c', similar unique thing condition

                while(hi > lo)
                {

                    int sum = nums[lo] + nums[hi];

                    if(sum < target)
                    {
                        while(lo < n && nums[lo] == pb)
                        {
                            lo++;
                        }
                        if(lo < n)
                        {
                            pb = nums[lo];
                        }
                    }
                    else if(sum > target)
                    {
                        while(hi > i && nums[hi] == pc)
                        {
                            hi--;
                        }
                        if(hi > i)
                        {
                            pc = nums[hi];
                        }
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo < n && nums[lo] == pb)
                        {
                            lo++;
                        }
                        if(lo < n)
                        {
                            pb = nums[lo];
                        }
                        while(hi > i && nums[hi] == pc)
                        {
                            hi--;
                        }
                        if(hi > i)
                        {
                            pc = nums[hi];
                        }
                    }
                }
                // prvious a gets updated here.
                preva = nums[i];
            }
        }

        return res;
    }
};
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int previ = 1e6;
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++)
        {
            long long int prevj = 1e6;
            if(nums[i] != previ)
            {
                for(int j = i + 1; j < n - 2; j++)
                {
                    long long int prevk = 1e6, prevl = 1e6;
                    if(nums[j] != prevj)
                    {
                        long long int k = j + 1;
                        long long int l = n - 1;

                        long long int tgt = (target - nums[i]);
                        tgt -= nums[j];

                        prevk = nums[k];
                        prevl = nums[l];

                        while(l > k)
                        {
                            long long int sum = nums[k] + nums[l];

                            if(sum < tgt)
                            {
                                while(k < n && nums[k] == prevk)
                                {
                                    k++;
                                }
                                if(k < n)
                                {
                                    prevk = nums[k];
                                }
                            }
                            else if(sum > tgt)
                            {
                                while(l > j && nums[l] == prevl)
                                {
                                    l--;
                                }
                                if(l > j)
                                {
                                    prevl = nums[l];
                                }
                            }
                            else
                            {
                                vector<int> temp;
                                temp.push_back((int) nums[i]);
                                temp.push_back((int) nums[j]);
                                temp.push_back((int) nums[k]);
                                temp.push_back((int) nums[l]);
                                ans.push_back(temp);

                                while(k < n && nums[k] == prevk)
                                {
                                    k++;
                                }
                                if(k < n)
                                {
                                    prevk = nums[k];
                                }

                                while(l > i && nums[l] == prevl)
                                {
                                    l--;
                                }
                                if(l > i)
                                {
                                    prevl = nums[l];
                                }
                            }
                        }
                        prevj = nums[j];
                    }
                }
                previ = nums[i];
            }
        }
        return ans;
    }
};
class Solution
{
public:
    long long minimalKSum(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            long long cur = nums[i];
            long long prev = (i > 0 ? nums[i - 1] : 0);
            long long ppl = (cur - prev - 1);

            if(ppl > 0)
            {
                if(ppl < k)
                {
                    k -= ppl;
                    ans += ((cur) * (cur - 1)) / 2;
                    ans -= (prev * (prev + 1)) / 2;
                }
                else if(ppl >= k)
                {
                    cur = prev + k + 1;
                    ans += ((cur) * (cur - 1)) / 2;
                    ans -= (prev * (prev + 1)) / 2;
                    return ans;
                }
            }

        }

        if(k > 0)
        {
            long long prev = nums.back();
            long long cur = prev + k + 1;
            ans += ((cur) * (cur - 1)) / 2;
            ans -= (prev * (prev + 1)) / 2;
        }

        return ans;
    }
};
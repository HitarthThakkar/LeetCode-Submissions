class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        // 2025 Hiring Prep Sprint Week_2 Q3

        int n = nums.size();
        int left = 0;
        int right = 0;
        long long int mul = 1;

        vector<pair<int, int>> vp;

        while(right < n)
        {
            mul *= nums[right];
            if(mul >= k)
            {
                if(left < right) vp.push_back({left, right - 1});
                while(left <= right && mul >= k) mul /= nums[left++];
            }
            right++;
        }

        if(left < right) vp.push_back({left, right - 1});

        int answer = 0;
        int prevend = -1;

        for(int i = 0; i < vp.size(); i++)
        {
            int a = vp[i].first;
            int b = vp[i].second;
            int l = b - a + 1;
            answer += (l * (l + 1) / 2);
            if(prevend >= a)
            {
                int ll = prevend - a + 1;
                int overlapping = (ll * (ll + 1) / 2);
                answer -= overlapping;
            }
            prevend = b;
        }

        return answer;
    }
};
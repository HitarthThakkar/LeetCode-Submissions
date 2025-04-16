class Solution
{
public:
    long long countGood(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        int left = 0;
        int right = 0;
        int n = nums.size();
        long long answer = 0;
        int no_of_pairs = 0;

        while(right < n)
        {
            m[nums[right]]++;

            if(m[nums[right]] > 1)
            {
                int oldFreq = m[nums[right]] - 1; 
                no_of_pairs -= ((oldFreq) * (oldFreq - 1) / 2);
                no_of_pairs += ((m[nums[right]]) * (m[nums[right]] - 1) / 2);
            }

            while(no_of_pairs >= k)
            {
                answer += (n - right);
                m[nums[left]]--;
                if(m[nums[left]] > 0)
                {
                    int oldFreq = m[nums[left]] + 1;
                    no_of_pairs -= ((oldFreq) * (oldFreq - 1) / 2);
                    no_of_pairs += ((m[nums[left]]) * (m[nums[left]] - 1) / 2);
                }
                left++;
            }

            right++;
        }

        return answer;
    }
};
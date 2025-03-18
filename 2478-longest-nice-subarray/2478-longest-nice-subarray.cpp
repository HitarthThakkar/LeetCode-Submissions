class Solution
{
private:
    void add(int n, vector<int> &mp)
    {
        int i = 0;
        while(n)
        {
            if(n & 1) mp[i]++;
            n /= 2;
            i++;
        }
    }
    void remove(int n, vector<int> &mp)
    {
        int i = 0;
        while(n)
        {
            if(n & 1) mp[i]--;
            n /= 2;
            i++;
        }
    }
    bool anyoneGreaterThanOne(vector<int> &mp)
    {
        for(auto ele : mp) if(ele > 1) return true;
        return false;
    }
public:
    int longestNiceSubarray(vector<int>& nums)
    {
        int left = 0, right = 0, answer = 1;
        vector<int> mp(31, 0);
        while(right < nums.size())
        {
            add(nums[right], mp);
            while(anyoneGreaterThanOne(mp)) remove(nums[left++], mp);
            answer = max(right - left + 1, answer);
            right++;
        }
        return answer;
    }
};
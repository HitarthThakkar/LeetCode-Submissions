class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k %= n;
        if(k == 0) return;

        int gcd = __gcd(n, k);

        for(int i = 0; i < gcd; i++)
        {
            int dump = nums[i], ind = i;
            for(int j = 0; j < (n / gcd); j++)
            {
                int nind = ((ind + k) % n);
                swap(dump, nums[nind]);
                ind = nind;
            }
        }
    }
};
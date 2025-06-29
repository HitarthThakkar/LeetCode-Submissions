class Solution
{
public:
    int powermod(long long x, int y, int p) {
        long long res = 1; x = x % p;
        if (x == 0) return 0;
        while (y > 0) { if (y & 1) res = (res * 1LL * x) % p; y = y >> 1; x = (x * 1LL* x) % p; }
        return (res % p);
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0; int mod = (1e9+7);
        for(int i = 0; i < n; i++) {
            int toFind = target - nums[i];
            int index = upper_bound(nums.begin(), nums.end(), toFind) - nums.begin();
            if(index < n && nums[index] != toFind) index--;
            if(index < i) return result; if(index == n) index--;
            int tbp = index - i;
            result += powermod(2, tbp, mod); result %= mod;
        }
        return result;
    }
};
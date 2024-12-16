/*  
    previous submission was here before this came and it was mind-fuckingly
    long but ut was correct and i personally made modulo mistakes and i 
    liked it so this que is actually MODULO QUESTION.
    but u can look the soln easy as this one is.
    so just see the soln for the concept shit for this particular que.
    but if actually want to learn that why is this hard then goto last
    submission and see actual implementation that you would do and how u
    actually fuck things.
    - Hitarth @16th-dec-2024-7:14pm
*/

#define ll long long 
class Solution {
    const int mod = 1e9+7;

    int modpow(long base, int exp) {
        long result = 1;
        while (exp) {
            if (exp & 1) {
                result *= base;
                result %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return result;
    }

public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        if (mul == 1) return nums;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = nums.size();
        ll maxi = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (k && 1LL*pq.top().first * mul <= maxi) {
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            val = (val * mul) % mod;
            pq.push({val, ind});
            k--;
        }

        int oldMul = mul;
        ll newMul = modpow(mul, k / n);

        vector<int> res(n);
        while (!pq.empty()) {
            ll val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            val = (val * newMul) % mod;
            if (k % n > 0) {
                val = (val * oldMul) % mod;
                k--;
            }

            res[ind] = val;
        }

        return res;
    }
};

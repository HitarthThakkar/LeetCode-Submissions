#define ll long long int
class Solution
{
private:
long long int powermod(long long base, long long exp)
{
    ll result = 1, mod = 1000000007;
    while(exp)
    {
        if(exp & 1)
        {
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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        if(multiplier == 1) return nums;
        ll mod = 1000000007;
        set<pair<ll, int>> s, ns, nns;
        int n = nums.size();
        for(int i = 0; i < n; i++) s.insert({1LL * nums[i], i});
        int limiter = ((--s.end())->first);
        while(( ((s.begin())->first * multiplier) <= limiter) && (k--))
        {
            pair<ll, int> get;
            get.first = s.begin()->first, get.second = s.begin()->second;
            get.first = ((get.first % mod) * (multiplier % mod));
            s.erase(s.begin());
            s.insert(get);
        }
        // cout << k << endl;
        if(k > 0)
        {
            ll megaMul = powermod(multiplier, (k / n));
            // cout << megaMul << endl;
            for(auto ele : s)
            {
                ll myNum = (((ele.first) % mod) * (megaMul % mod));
                ns.insert({myNum, ele.second});
            }
            // for(auto ele : ns) cout << ele.first << " "; cout << endl;
            ll leftK = (k % n);
            // cout << leftK << endl;
            for(int i = 0; i < leftK; i++)
            {
                pair<ll, int> get;
                get.first = ns.begin()->first, get.second = ns.begin()->second;
                get.first = ((get.first % mod) * (multiplier % mod));
                ns.erase(ns.begin());
                nns.insert(get);
            }
            for(auto ele : ns)
            {
                nns.insert(ele);
            }
        }
        else
        {
            for(auto ele : s)
            {
                nums[ele.second] = (ele.first % mod);
            }
            return nums;
        }
        for(auto ele : nns)
        {
            nums[ele.second] = (ele.first % mod);
        }
        return nums;
    }
};
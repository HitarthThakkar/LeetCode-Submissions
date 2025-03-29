class Solution
{
private:
    long long int powermod(long long int x, long long int y, long long int p)
    {
        long long int res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0)
        {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    void giveNGE(vector<int> &dpf, vector<int> &nge, int n)
    {
        stack<int> s;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() && dpf[s.top()] <= dpf[i]) s.pop();
            if(!s.empty()) nge[i] = s.top();
            s.push(i);
        }
    }
    void givePGEE(vector<int> &dpf, vector<int> &pgee, int n)
    {
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && dpf[s.top()] < dpf[i]) s.pop();
            if(!s.empty()) pgee[i] = s.top();
            s.push(i);
        }
    }
    void givedpfSieve(vector<int> &nums, vector<int> &dpf)
    {
        long long int maxN = *max_element(nums.begin(), nums.end());
        vector<int> primeFactSieve(maxN + 1, -1);
        for (long long int i = 2; i <= maxN; i++)
            if (primeFactSieve[i] == -1)
                for (long long int j = i * i; j <= maxN; j += i)
                    if (primeFactSieve[j] == -1)
                        primeFactSieve[j] = i;
        for(int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            // following line gave WA, and made me question my existance, 
            // overpowered than the whole code itself.
            if(number == 1) { dpf[i] = 0; continue; }
            set<int> dpfs;
            while(primeFactSieve[number] != -1) {
                dpfs.insert(primeFactSieve[number]);
                number /= primeFactSieve[number];
            }
            dpfs.insert(number);
            dpf[i] = dpfs.size();
        }
    }
public:
    int maximumScore(vector<int>& nums, int k)
    {
        int n = nums.size();
        long long int m = 1000000007;
        vector<int> dpf(n, 0);
        givedpfSieve(nums, dpf);
        // for(auto e : dpf) cout << e << " "; cout << endl;
        vector<int> nge(n, n), pgee(n, -1);
        giveNGE(dpf, nge, n);
        // for(auto e : nge) cout << e << " "; cout << endl;
        givePGEE(dpf, pgee, n);
        // for(auto e : pgee) cout << e << " "; cout << endl;
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++) vp.push_back({nums[i], i});
        sort(vp.rbegin(), vp.rend());
        long long int answer = 1;
        for(int i = 0; i < n; i++)
        {
            if(k == 0) return answer;
            long long int number = vp[i].first;
            long long int index = vp[i].second;
            long long int a = pgee[index] + 1;
            long long int b = nge[index] - 1;
            // cout << number << " " << a << " " << b << endl;
            long long int myContribution = ((index - a + 1) * (b - index + 1));
            // cout << myContribution << " " << k << endl;
            long long int mini = (k > myContribution ? myContribution : k);
            long long int toMul = powermod(number, mini, m);
            toMul %= m;
            // cout << toMul << " " << answer << endl;
            answer *= toMul;
            answer %= m;
            k -= mini;
            // cout << k << " " << answer << endl;
        }
        return answer;
    }
};
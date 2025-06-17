#define ll long long int

class factorial_ops
{
    public:
        //inv_fact[i] = 1 / fact[i]

        ll powermod(ll x, ll y, ll p)
        {
            int res = 1;
            x = x % p;
            if (x == 0) return 0;
            while (y > 0) {
                if (y & 1) res = (res * x) % p;
                y = y >> 1;
                x = (x * x) % p;
            }
            return res;
        }

        vector<ll> fact, inv_fact;
        ll MOD;
        int N;

        factorial_ops(int N, ll MOD)
        {
            this->N = N;
            this->MOD = MOD;
            fact.resize(N + 1, 0);
            inv_fact.resize(N + 1, 0);
        }

        void factorials()
        {
            fact[0] = 1;

            for(ll i = 1; i <= N; i++)
            {
                fact[i] = (fact[i - 1] * i) % MOD;
            }

            inv_fact[N] = powermod(fact[N], MOD - 2, MOD);

            for(ll i = N - 1; i >= 0; i--)
            {
                inv_fact[i] =  (inv_fact[i + 1] * (i + 1)) % MOD;
            }
        }

        ll ncr(int n, int k)
        {
            return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % MOD)) % MOD;
        }

        ll npr(int n,int k)
        {
            return ((fact[n]*inv_fact[n-k])%MOD);
        }
};

class Solution
{
public:
    ll powermod(ll x, ll y, ll p)
    {
        int res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1) res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    int countGoodArrays(int n, int m, int k)
    {
        if(k == n - 1) return m;
        ll mod = 1e9 + 7;
        factorial_ops fops(n, mod);
        fops.factorials();
        ll bunny = fops.ncr(n - 1, k);
        // cout << bunny << endl;
        bunny %= mod;
        // cout << bunny << endl;
        ll honey = powermod(m - 1, n - k - 1, mod);
        // cout << honey << endl;
        honey %= mod;
        // cout << honey << endl;
        ll mm = m;
        mm %= mod;
        // cout << m << endl;
        mm *= honey;
        // cout << m << endl;
        mm %= mod;
        // cout << m << endl;
        mm *= bunny;
        // cout << m << endl;
        mm %= mod;
        // cout << m << endl;
        return mm;
    }
};
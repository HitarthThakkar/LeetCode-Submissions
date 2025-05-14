#define ll long long

class Solution
{
public:
    int m = 1e9 + 7;

    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B)
    {
        vector<vector<ll>> result(A.size(), vector<ll>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B[0].size(); j++)
            {
                for (int k = 0; k < B.size(); k++)
                {
                    result[i][j] = (result[i][j] + ((A[i][k] % m) * (B[k][j] % m) % m)) % m;
                }
            }
        }
        
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums)
    {
        vector<vector<ll>> f(1, vector<ll> (26, 0));
        for(auto c : s) f[0][c - 'a']++;

        vector<vector<ll>> T(26, vector<ll> (26, 0));
        vector<vector<ll>> I(26, vector<ll> (26, 0));

        for(int i = 0; i < 26; i++)
        {
            int sp = i + 1;
            int times = nums[i];
            while(times--)
            {
                T[i][sp % 26] = 1;
                sp++;
            }
        }

        for(int i = 0; i < 26; i++)
        {
            I[i][i] = 1;
        }

        while(t > 0)
        {
            if(t & 1)
            {
                I = multiply(I, T);
                t--;
            }
            else
            {
                T = multiply(T, T);
                t /= 2;
            }
        }

        f = multiply(f, I);

        long long answer = 0;

        for(long long e : f[0])
        {
            answer = (((answer % m) + (e % m)) % m);
        }

        return ((int) (answer % m));
    }
};
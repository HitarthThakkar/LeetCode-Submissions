#define ll long long int
class Solution
{
public:
    long long minTime(vector<int>& skill, vector<int>& mana)
    {
        int n = skill.size();
        int m = mana.size();

        // t[i][j] == mana[i] * skill[j];

        vector<vector<ll>> v(m, vector<ll> (n, 0));

        for(int i = 0; i < n; i++)
        {
            if(i - 1 >= 0) v[0][i] = v[0][i - 1] + (mana[0] * skill[i]);
            else v[0][i] = mana[0] * skill[i];
        }

        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                if(i - 1 >= 0)
                    v[j][i] = max(v[j - 1][i], v[j][i - 1]) + (mana[j] * skill[i]);
                else v[j][i] = v[j - 1][i] + (mana[j] * skill[i]);
            }
            for(int i = n - 2; i >= 0; i--)
            {
                v[j][i] = v[j][i + 1] - (mana[j] * skill[i + 1]);
            }
        }

        return v[m - 1][n - 1];
    }
};
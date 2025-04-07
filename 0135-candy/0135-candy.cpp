class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();

        if(n == 1) return 1;

        vector<int> v(n, 1);

        for(int i = 0; i < n; i++)
        {
            int his = ratings[i];
            if(i == 0)
            {
                int nr = ratings[i + 1];

                if(his > nr)
                {
                    v[i] = v[i + 1] + 1;
                }
            }
            else if(i == n - 1)
            {
                int nr = ratings[i - 1];

                if(his > nr)
                {
                    v[i] = v[i - 1] + 1;
                }

            }
            else
            {
                int nr1 = ratings[i - 1];
                int nr2 = ratings[i + 1];

                if(his > nr1 && his > nr2)
                {
                    v[i] = max(v[i - 1], v[i + 1]) + 1;
                }
                else if(his > nr1)
                {
                    v[i] = v[i - 1] + 1;
                }
                else if(his > nr2)
                {
                    v[i] = v[i + 1] + 1;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--)
        {
            int his = ratings[i];
            if(i == 0)
            {
                int nr = ratings[i + 1];

                if(his > nr)
                {
                    v[i] = v[i + 1] + 1;
                }
            }
            else if(i == n - 1)
            {
                int nr = ratings[i - 1];

                if(his > nr)
                {
                    v[i] = v[i - 1] + 1;
                }

            }
            else
            {
                int nr1 = ratings[i - 1];
                int nr2 = ratings[i + 1];

                if(his > nr1 && his > nr2)
                {
                    v[i] = max(v[i - 1], v[i + 1]) + 1;
                }
                else if(his > nr1)
                {
                    v[i] = v[i - 1] + 1;
                }
                else if(his > nr2)
                {
                    v[i] = v[i + 1] + 1;
                }
            }

        }

        return accumulate(v.begin(), v.end(), 0);
    }
};
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();

        vector<int> v;
        for (auto ele : colors)
            v.push_back(ele);
        for (auto ele : colors)
            v.push_back(ele);

        // debug(v);

        int zei = 0, zoi = 0, ooi = 0, oei = 0;

        for (int i = 0; i < k - 1; i++)
        {
            if (v[i] == 0)
            {
                if (i & 1)
                {
                    zoi++;
                }
                else
                {
                    zei++;
                }
            }
            if (v[i] == 1)
            {
                if (i & 1)
                {
                    ooi++;
                }
                else
                {
                    oei++;
                }
            }
        }

        // debug(zei, zoi, ooi, oei);

        int ans = 0;

        for (int ep = k - 1; ep <= n + k - 2; ep++)
        {
            int sp = ep - k + 1;

            // debug(sp, ep);

            if (ep & 1)
            {
                if (v[ep] == 0)
                    zoi++;
                else
                    ooi++;
            }
            else
            {
                if (v[ep] == 0)
                    zei++;
                else
                    oei++;
            }

            // debug(zei, zoi, ooi, oei);

            if (sp & 1)
            {
                if (v[sp] == 0)
                {
                    if (zei == 0 && ooi == 0)
                    {
                        ans++;
                    }
                    zoi--;
                }
                else
                {
                    if (oei == 0 && zoi == 0)
                    {
                        ans++;
                    }
                    ooi--;
                }
            }
            else
            {
                if (v[sp] == 0)
                {
                    if (zoi == 0 && oei == 0)
                    {
                        ans++;
                    }
                    zei--;
                }
                else
                {
                    if (zei == 0 && ooi == 0)
                    {
                        ans++;
                    }
                    oei--;
                }
            }

            // debug(zei, zoi, ooi, oei);
        }

        return ans;
    }
};
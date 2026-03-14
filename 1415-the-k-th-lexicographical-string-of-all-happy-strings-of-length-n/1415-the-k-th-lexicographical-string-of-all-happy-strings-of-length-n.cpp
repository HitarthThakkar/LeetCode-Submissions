class Solution
{
public:

    void recur(int l, int r, int left, string &res, int k)
    {
        if(left == 0) return;

        int length = r - l + 1;
        int mid = length / 2;

        if(k <= mid)
        {
            if(res.back() == 'a') res += 'b';
            else res += 'a';

            recur(l, l + mid - 1, left - 1, res, k);
        }
        else
        {
            k -= mid;

            if(res.back() == 'c') res += 'b';
            else res += 'c';

            recur(l + mid, r, left - 1, res, k);
        }
    }

    string getHappyString(int n, int k)
    {
        int mexK = pow(2, n - 1) * 3;
        if(k > mexK) return "";

        int cut = mexK / 3;
        // (1, cut), (cut+1, 2*cut), (2*cut + 1, 3*cut)

        int sp = 1;
        int ep = cut;

        string res = "";

        if(sp <= k && k <= ep)
        {
            res += 'a';
            recur(sp, ep, n - 1, res, k);
            return res;
        }

        sp = cut + 1;
        ep = 2 * cut;

        if(sp <= k && k <= ep)
        {
            res += 'b';
            int remK = k - cut;
            recur(sp, ep, n - 1, res, remK);
            return res;
        }

        sp = (2 * cut) + 1;
        ep = 3 * cut;

        if(sp <= k && k <= ep)
        {
            res += 'c';
            int remK = k - (2 * cut);
            recur(sp, ep, n - 1, res, remK);
            return res;
        }

        return "";
    }
};
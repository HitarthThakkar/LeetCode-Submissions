class Solution
{
public:

    int recur(int l, int r, int d, int ss)
    {
        if(l == r) return l;

        int remaining = (r - l) / ss + 1;

        if(d == 1)
        {
            int nl = l + ss;
            int nr = r;
            if(remaining & 1) nr = r - ss;
            return recur(nl, nr, -1, ss * 2);
        }
        else
        {
            int nr = r - ss;
            int nl = l;
            if(remaining & 1) nl = l + ss;
            return recur(nl, nr, 1, ss * 2);
        }
    }

    int lastRemaining(int n)
    {
        return recur(1, n, 1, 1);
    }
};
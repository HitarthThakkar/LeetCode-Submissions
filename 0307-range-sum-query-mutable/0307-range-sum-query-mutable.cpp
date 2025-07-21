struct segtree
{
    int size;
    vector<int> sums;

    void init(int n)
    {
        size = 1;
        while(size < n) size <<= 1;
        sums.assign(2 * size, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            sums[x] = v;
            return;
        }

        int m = (lx + rx) / 2;

        if(i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx)
    {
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return sums[x];

        int m = (lx + rx) / 2;

        int s1 = sum(l, r, 2 * x + 1, lx, m);
        int s2 = sum(l, r, 2 * x + 2, m, rx);

        return s1 + s2;
    }

    int sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
};

class NumArray
{
public:

    segtree st;

    NumArray(vector<int>& nums)
    {
        st.init(nums.size());

        for(int i = 0; i < nums.size(); i++)
        {
            st.set(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        st.set(index, val);
    }
    
    int sumRange(int left, int right)
    {
        return st.sum(left, right + 1);
    }
};
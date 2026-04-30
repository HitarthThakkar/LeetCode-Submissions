class SegTree {
    int n;
    vector<long long> tree;

    void update(int node, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(node << 1, l, mid, pos, val);
        else update(node << 1 | 1, mid + 1, r, pos, val);

        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;   // 0 is neutral because nums[i] >= 1
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;
        return max(query(node << 1, l, mid, ql, qr),
                   query(node << 1 | 1, mid + 1, r, ql, qr));
    }

public:
    SegTree(int n) : n(n), tree(4 * n + 5, 0) {}

    void update(int pos, long long val) {
        update(1, 1, n, pos, val);
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(1, 1, n, l, r);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAXV = 100000;

        SegTree incTree(MAXV), decTree(MAXV);

        vector<long long> inc(n), dec(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                int j = i - k;
                incTree.update(nums[j], inc[j]);
                decTree.update(nums[j], dec[j]);
            }

            // Start with single element subsequence
            inc[i] = dec[i] = nums[i];

            // prev < nums[i] => extend a decreasing-ending subsequence
            long long bestDec = decTree.query(1, nums[i] - 1);
            inc[i] = max(inc[i], (long long)nums[i] + bestDec);

            // prev > nums[i] => extend an increasing-ending subsequence
            long long bestInc = incTree.query(nums[i] + 1, MAXV);
            dec[i] = max(dec[i], (long long)nums[i] + bestInc);

            ans = max({ans, inc[i], dec[i]});
        }

        return ans;
    }
};
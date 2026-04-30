class Solution
{
public:

    vector<long long> segUp = vector<long long>(4 * 100010, 0);
    vector<long long> segDown = vector<long long>(4 * 100010, 0);

    void update(int index, int l, int r, vector<long long>& tree, long long pos, long long val)
    {
        if(index >= tree.size()) return;
        if(pos < l || pos > r) return;
        if(l == r) {
            tree[index] = max(tree[index], val);
            return;
        }
        int mid = (l + r) / 2;
        update(index*2, l, mid, tree, pos, val);
        update(index*2+1, mid+1, r, tree, pos, val);
        long long left = (2*index < tree.size()) ? tree[2*index] : -1;
        long long right = (2*index+1 < tree.size()) ? tree[2*index+1] : -1;
        tree[index] = max(left, right);
        // tree[index] = max(tree[2*index], tree[2*index+1]);
    }

    long long query(int index, int l, int r, vector<long long> &tree, int lq, int rq)
    {
        if(index >= tree.size()) return -1;
        if(l > r) return -1;
        if(l > rq || lq > r) return -1;
        if(lq <= l && r <= rq)
        {
            return tree[index];
        }
        int mid = (l + r) / 2;
        return (max(query(index*2, l, mid, tree, lq, rq), query(index*2+1, mid+1, r, tree, lq, rq)));
    }

    long long maxAlternatingSum(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<long long> dpUp(n, -1), dpDown(n, -1);

        for(int i = 0; i < n; i++)
        {
            // nums[i] is current element and we want to find where to put him as an upper and downer.

            if(i >= k)
            {
                // adding 'i-k'th one in both seg trees
                // dpUp[i - k] has a val which says i am big, so segUp[nums[i-k]] should have the dpUp[i-k] val
                update(1, 0, 100010, segUp, nums[i - k], dpUp[i - k]);
                // similar shid
                update(1, 0, 100010, segDown, nums[i - k], dpDown[i - k]);
            }

            // length 1 sequence
            dpUp[i] = dpDown[i] = nums[i];

            // dpDown[i] -> i - 1 > i so now looking for big
            // dpUp[i] -> i - 1 < i so now looking for small

            // query for max value for dpUp(segUp) from nums[i] + 1 to mex and write in dpDown[i]
            long long mexPrevUp = query(1, 0, 100010, segUp, nums[i] + 1, 100010);
            dpDown[i] = max(dpDown[i], mexPrevUp + nums[i]);
            // query for max value for dpDown(segDown) from 0 to nums[i] - 1 and write in dpUp[i]
            long long mexPrevDown = query(1, 0, 100010, segDown, 0, nums[i] - 1);
            dpUp[i] = max(dpUp[i], mexPrevDown + nums[i]);
        }

        long long res = 0;
        for(auto e : dpUp) res = max(res, e);
        for(auto e : dpDown) res = max(res, e);
        return res;
    }
};
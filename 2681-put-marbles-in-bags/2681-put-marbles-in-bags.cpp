class Solution
{
public:
    long long putMarbles(vector<int>& weights, int k)
    {
        int n = weights.size();
        vector<int> heap;
        for(int i = 0; i < n - 1; i++) heap.push_back(weights[i] + weights[i + 1]);
        sort(heap.begin(), heap.end());
        long long mex = 0, mini = 0;
        for(int i = 0; i < k - 1; i++) mini += heap[i];
        for(int i = 0; i < k - 1; i++) { mex += heap.back(); heap.pop_back(); }
        return mex - mini;
    }
};
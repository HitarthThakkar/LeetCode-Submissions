class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int r = 0, ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            r = max(r, arr[i]);
            if(r <= i) ans++, r = i;
        }
        return ans;
    }
};
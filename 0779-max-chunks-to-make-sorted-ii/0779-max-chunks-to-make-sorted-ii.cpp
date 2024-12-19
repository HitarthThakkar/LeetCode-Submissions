class Solution
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int r = 0, ans = 0, n = arr.size();
        vector<int> v = arr; sort(v.begin(), v.end());
        map<int, int> m;
        for(int i = 0; i < n; i++) if(m.find(v[i]) == m.end()) m[v[i]] = i;
        for(int i = 0; i < n; i++)
        {
            r = max(r, m[arr[i]]++);
            if(r <= i) ans++, r = i;
        }
        return ans;
    }
};
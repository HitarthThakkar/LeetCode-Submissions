class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int ans = 0;
        multiset<int> ms;
        for(auto ele : s) ms.insert(ele);
        for(auto ele : g)
        {
            auto it = ms.lower_bound(ele);
            if(it != ms.end())
            {
                ans++;
                ms.erase(it);
            }
        }
        return ans;
    }
};
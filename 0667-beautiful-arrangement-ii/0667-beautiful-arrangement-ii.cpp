class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> all, res;
        for(int i = 1; i <= n; i++) all.push_back(i);
        int i = 0;
        while(k < n)
        {
            res.push_back(all[i++]);
            k++;
        }

        int j = n-1;

        while(i <= j)
        {
            res.push_back(all[j--]);
            if(i < j) res.push_back(all[i++]);
        }

        return res;
    }
};
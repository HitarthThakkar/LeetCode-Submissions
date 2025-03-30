class Solution
{
public:
    vector<int> v;
    int sum;
    Solution(vector<int>& w)
    {
        v.push_back(w[0]);
        for(int i = 1; i < w.size(); i++) v.push_back(v.back() + w[i]);
        sum = v.back();
    }
    int pickIndex()
    {
        long long int r = (rand() % sum) + 1;
        int ind = lower_bound(v.begin(), v.end(), r) - v.begin();
        return ind;
    }
};
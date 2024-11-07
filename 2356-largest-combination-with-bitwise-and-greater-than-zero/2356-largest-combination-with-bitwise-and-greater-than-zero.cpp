class Solution
{
public:
    int largestCombination(vector<int>& candidates)
    {
        vector<int> bc(32, 0);
        for(auto ele : candidates)
        {
            int n = ele, i = 0;
            while(n) { if(n & 1) bc[i]++; n /= 2; i++; }
        }
        int mexi = -1;
        for(auto ele : bc) if(ele > mexi) mexi = ele;
        return mexi;
    }
};
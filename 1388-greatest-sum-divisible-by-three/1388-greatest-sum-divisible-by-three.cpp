class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int result = 0;
        vector<int> one, two;
        for(auto e : nums)
        {
            if(e % 3 == 0) result += e;
            else if(e % 3 == 1) one.push_back(e);
            else two.push_back(e);
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int onesum = accumulate(one.begin(), one.end(), 0);
        int twosum = accumulate(two.begin(), two.end(), 0);
        int os = one.size();
        int ts = two.size();
        int times = 3;
        int tba = 0;
        while(times--)
        {
            int nta = os % 3;
            int ntb = ts % 3;
            int cur = onesum + twosum;
            int i = 0;
            while(nta--) cur -= one[i++];
            i = 0;
            while(ntb--) cur -= two[i++];
            tba = max(tba, cur);
            if(os > 0 && ts > 0) { os--; ts--; }
            else break;
        }
        return (result + tba);
    }
};
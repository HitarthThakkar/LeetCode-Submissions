class Solution
{
public:
    int minimumEffort(vector<vector<int>>& tasks)
    {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            int d1 = a[1] - a[0];
            int d2 = b[1] - b[0];
            return d1 > d2;
        });

        long long alr = 0;
        long long res = 0;

        for(auto v : tasks)
        {
            if(alr < v[1])
            {
                long long toAdd = v[1] - alr;
                res += toAdd;
                alr += toAdd;
            }

            alr -= v[0];
        }

        return res;
    }
};
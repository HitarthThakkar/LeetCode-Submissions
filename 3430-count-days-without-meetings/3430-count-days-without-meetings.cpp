class Solution
{
public:
    int countDays(int days, vector<vector<int>>& meetings)
    {
        map<int, int> pfxmp;

        pfxmp[0] = 0;
        pfxmp[days + 1] = 1;

        for(auto e : meetings)
        {
            pfxmp[e[0]]++;
            pfxmp[e[1] + 1]--;
        }

        int runningsum = 0;
        int answer = 0;

        while(!pfxmp.empty())
        {
            auto it = pfxmp.begin();

            runningsum += it->second;

            if(runningsum == 0)
            {
                auto itr = it;
                itr++;
                if(itr != pfxmp.end())
                {
                    answer += (itr->first - it->first);
                }
            }

            pfxmp.erase(pfxmp.begin());
        }

        return (--answer);
    }
};
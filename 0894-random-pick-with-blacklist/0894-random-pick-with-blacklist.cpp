class Solution
{
public:
    int N;
    vector<int> modified, whiteList;
    bool nearlyAllBlacklisted = false;
    Solution(int n, vector<int>& blacklist)
    {
        long long int blacklisted = blacklist.size();
        if(blacklisted >= (1LL * n * 3 / 4)) nearlyAllBlacklisted = true;
        if(nearlyAllBlacklisted)
        {
            set<int> finder(blacklist.begin(), blacklist.end());
            for(int i = 0; i < n; i++)
            {
                if(finder.find(i) == finder.end())
                {
                    whiteList.push_back(i);
                }
            }
        }
        else
        {
            N = n; modified = blacklist;
            modified.push_back(n); modified.push_back(-1);
            sort(modified.begin(), modified.end());
        }
    }
    int pick()
    {
        if(nearlyAllBlacklisted)
        {
            int r = rand() % whiteList.size();
            return whiteList[r];
        }
        else
        {
            int left = 2, right = 1;
            while(left > right)
            {
                int r = rand() % N;
                int ind = lower_bound(modified.begin(), modified.end(), r) - modified.begin();
                left = modified[ind - 1] + 1;
                right = modified[ind] - 1;
            }
            int rr = rand() % (right - left + 1) + left;
            return rr;
        }
    }
};
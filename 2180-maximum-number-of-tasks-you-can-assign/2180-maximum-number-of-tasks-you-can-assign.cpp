class Solution
{
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        int result = 0;
        int lo = 0, hi = min(tasks.size(), workers.size());

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;

            int usedPills = 0;
            multiset<int> workersFree(workers.end() - mid, workers.end());

            bool canAssign = true;

            for(int i = mid - 1; i >= 0; i--)
            {
                auto it = prev(workersFree.end());

                if(*it < tasks[i])
                {
                    it = workersFree.lower_bound(tasks[i] - strength);

                    if(it == workersFree.end())
                    {
                        canAssign = false;
                        break;
                    }

                    usedPills++;

                    if(usedPills > pills)
                    {
                        canAssign = false;
                        break;
                    }
                }

                workersFree.erase(it);
            }

            if(canAssign) { result = mid; lo = mid + 1; }
            else hi = mid - 1;
        }

        return result;
    }
};
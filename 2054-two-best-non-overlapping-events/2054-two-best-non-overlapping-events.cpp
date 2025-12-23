class Solution
{
public:

    static bool compareFirstElement(int val, const std::vector<int>& vec) {
        // Compare against the 0th element of the inner vector
        return val < vec[0];
    }

    static bool compareFirstElement2(const std::vector<int>& vec, int val) {
        // Compare against the 0th element of the inner vector
        return vec[0] < val;
    }

    int maxTwoEvents(vector<vector<int>>& events)
    {
        int n = events.size();

        // StartTime Sorted Events for getting after best
        vector<vector<int>> ssEvents = events;
        // EndTime Sorted Events for getting before best
        vector<vector<int>> esEvents = events;

        // we've sorted by start time, WOW!
        sort(ssEvents.begin(), ssEvents.end());

        for(auto &e : esEvents) swap(e[0], e[1]);
        // now we've cleverly sorted it by end time, WOW!
        sort(esEvents.begin(), esEvents.end());

        // suffix max value of startTime Sorted Events, you will realize why we need it.
        for(int i = n - 2; i >= 0; i--) {
            ssEvents[i][2] = max(ssEvents[i][2], ssEvents[i + 1][2]);
        }

        // will store max of left best and right best to get final best finally.
        vector<int> best(n, 0);


        // populating right best for all events
        for(int i = 0; i < n; i++)
        {
            // to be a 'valid' right they have to start after cur event's end time
            int startAfterMe = events[i][1];

            // binary searching the first valid right index
            int ind = upper_bound(ssEvents.begin(), ssEvents.end(), startAfterMe, compareFirstElement) - ssEvents.begin();

            // ofc
            if(ind >= n) continue;

            // here we be using suffix max value to finally populate right best.
            best[i] = max(best[i], ssEvents[ind][2]);
        }

        // now we need prefix max value of EndTime Sorted Events, for left best.
        for(int i = 1; i < n; i++)
        {
            esEvents[i][2] = max(esEvents[i][2], esEvents[i - 1][2]);
        }

        // populating left best for all events
        for(int i = 0; i < n; i++)
        {
            // to be a 'valid' left they have to end before cur event's start time
            int endBeforeMe = events[i][0];

            // binary searching less or equal
            int ind = lower_bound(esEvents.begin(), esEvents.end(), endBeforeMe, compareFirstElement2) - esEvents.begin();

            // We need strictly lesser boyy
            if(ind < n && esEvents[ind][0] >= endBeforeMe) ind--;

            // using prefix max value to finally populate left best.
            if(ind >= 0 && ind < n) best[i] = max(best[i], esEvents[ind][2]);
        }

        // best is ready to use, which has all events' best valid pair value. [either from left or right]
        
        int res = 0;

        for(int i = 0; i < n; i++)
        {
            res = max(res, events[i][2] + best[i]);
        }

        return res;
    }
};
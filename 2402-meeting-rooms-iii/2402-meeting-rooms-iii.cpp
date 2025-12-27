class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        set<int> unocc;
        for(int i = 0; i < n; i++) unocc.insert(i);
        vector<long long> cnt(n, 0);

        for(auto m : meetings)
        {
            while(pq.size() > 0 && pq.top().first <= m[0])
            {
                unocc.insert(pq.top().second);
                pq.pop();
            }

            if(unocc.size() > 0)
            {
                int cri = *unocc.begin();   // Chosen Room Index
                unocc.erase(unocc.begin());
                pq.push({m[1], cri});
                cnt[cri]++;
            }
            else
            {
                long long startTime = max(pq.top().first, 1LL * m[0]);
                int roomIndex = pq.top().second;
                long long duration = m[1] - m[0];

                pq.pop();
                cnt[roomIndex]++;
                pq.push({startTime + duration, roomIndex});
            }
        }

        int prevmex = -1;
        int prevmexind = -1;

        for(int i = 0; i < n; i++)
        {
            if(cnt[i] > prevmex)
            {
                prevmex = cnt[i];
                prevmexind = i;
            }
        }

        return prevmexind;
    }
};
#define pai pair<long long int, int>

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        sort(meetings.begin(), meetings.end()); // ESSENTIAL

        vector<int> freq(n, 0);
        priority_queue<int, vector<int>, greater<int>> available; // {index}
        priority_queue<pai, vector<pai>, greater<pai>> ongoing; // {ending_time, index}

        for(int i = 0; i < n; i++) available.push(i);

        for(int i = 0; i < meetings.size(); i++)
        {
            // empty out ongoing meeting rooms if ending at time <= meetings[i][0]
            while(!ongoing.empty() && ongoing.top().first <= meetings[i][0])
            {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            // check whether available queue has something
            // if yes pop first one and push into ongoing correctly
            // if not then pop one from ongoing and do the same
            int meeting_duration = meetings[i][1] - meetings[i][0];

            if(available.empty())
            {
                long long int time = ongoing.top().first;
                int index = ongoing.top().second;
                ongoing.pop();
                freq[index]++;
                ongoing.push({1LL * (time + 0LL + meeting_duration), index});
            }
            else
            {
                int index = available.top();
                available.pop();
                freq[index]++;
                ongoing.push({1LL * (meetings[i][0] + 0LL + meeting_duration), index});
            }
        }

        int mex = *max_element(freq.begin(), freq.end());
        for(int i = 0; i < n; i++) if(freq[i] == mex) return i;
        return -1;
    }
};
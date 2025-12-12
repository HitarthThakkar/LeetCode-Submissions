class Solution
{
public:

    bool isOnline(int uId, int timestamp, vector<set<int>> &offlineIntervals)
    {
        auto it = offlineIntervals[uId].upper_bound(timestamp);
        if(it == offlineIntervals[uId].begin()) return true;
        it--;
        int offlineEventTime = *it;
        return (!((offlineEventTime <= timestamp) && (timestamp <= (offlineEventTime + 59))));
    }

    vector<int> getIdsFromString(string s)
    {
        vector<int> result;

        string temp = "";

        for(auto c : s)
        {
            if(c == 'i' || c == 'd') continue;
            else if(c == ' ')
            {
                result.push_back(stoi(temp));
                temp = "";
            }
            else temp.push_back(c);
        }

        if(temp != "") result.push_back(stoi(temp));

        return result;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events)
    {
        vector<set<int>> offlineIntervals(numberOfUsers);

        for(auto e : events)
        {
            if(e[0] == "OFFLINE")
            {
                int timestamp = stoi(e[1]);
                int id = stoi(e[2]);
                offlineIntervals[id].insert(timestamp);
            }
        }

        int allCount = 0;
        vector<int> mentions(numberOfUsers, 0);

        for(auto e : events)
        {
            if(e[0] != "OFFLINE")
            {
                int timestamp = stoi(e[1]);

                if(e[2][0] == 'A')
                {
                    allCount++;
                }
                else if(e[2][0] == 'H')
                {
                    for(int id = 0; id < numberOfUsers; id++)
                    {
                        if(isOnline(id, timestamp, offlineIntervals))
                        {
                            mentions[id]++;
                        }
                    }
                }
                else
                {
                    vector<int> mentionedIds = getIdsFromString(e[2]);

                    for(auto id : mentionedIds)
                    {
                        mentions[id]++;
                    }
                }
            }
        }

        for(auto &e : mentions)
        {
            e += allCount;
        }

        return mentions;
    }
};
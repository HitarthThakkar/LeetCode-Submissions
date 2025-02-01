class Solution {
public:
int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
{
    int n = startTime.size();

    int prevtime = 0;

    vector<int> ttl;
    vector<pair<int, int>> br;

    for (int i = 0; i < n; i++)
    {
        int diff = startTime[i] - prevtime;
        br.push_back({diff, ttl.size()});
        ttl.push_back(diff);
        ttl.push_back(endTime[i] - startTime[i]);
        prevtime = endTime[i];
    }

    int diff = eventTime - prevtime;
    br.push_back({diff, ttl.size()});
    ttl.push_back(diff);

    // debug(br);
    // debug(ttl);

    sort(br.begin(), br.end());

    vector<int> b1, b2;

    for (auto ele : br)
    {
        b1.push_back(ele.first);
        b2.push_back(ele.second);
    }

    // debug(br);
    // debug(b1);
    // debug(b2);

    int ans = 0;

    for (int i = 2; i < ttl.size(); i += 2)
    {
        ans = max(ans, ttl[i] + ttl[i - 2]);
    }

    // debug(ans);

    for (int i = 1; i < ttl.size(); i += 2)
    {

        // debug(i, ans);

        set<int> st;
        st.insert(i - 1);
        st.insert(i + 1);

        int val = ttl[i];

        int b1sz = b1.size();

        int index = lower_bound(b1.begin(), b1.end(), val) - b1.begin();
        // debug(index);

        int noele_geq_val = b1sz - index;

        if (noele_geq_val > 2)
        {
            int newval = ttl[i] + ttl[i - 1] + ttl[i + 1];
            ans = max(ans, newval);
        }
        else if (noele_geq_val == 2)
        {
            int find = b2[index];
            int sind = b2[index + 1];

            if (st.find(find) == st.end() || st.find(sind) == st.end())
            {
                int newval = ttl[i] + ttl[i - 1] + ttl[i + 1];
                ans = max(ans, newval);
            }
        }
        else if (noele_geq_val == 1)
        {
            if (st.find(b2[index]) == st.end())
            {
                int newval = ttl[i] + ttl[i - 1] + ttl[i + 1];
                ans = max(ans, newval);
            }
        }
    }

    return ans;
}
};
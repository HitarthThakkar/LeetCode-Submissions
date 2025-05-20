class Twitter
{
public:
    map<int, unordered_set<int>> mp;
    vector<pair<int, int>> vp;
    Twitter() {}
    void postTweet(int userId, int tweetId) { vp.push_back({userId, tweetId}); }
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = vp.size() - 1; i >= 0; i--) {
            if(vp[i].first == userId || mp[userId].find(vp[i].first) != mp[userId].end())
                res.push_back(vp[i].second);
            if(res.size() == 10) break;
        }
        return res;
    }
    void follow(int followerId, int followeeId) { mp[followerId].insert(followeeId); }
    void unfollow(int followerId, int followeeId) { mp[followerId].erase(followeeId); }
};
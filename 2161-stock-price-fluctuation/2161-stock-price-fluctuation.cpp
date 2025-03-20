class StockPrice
{
public:
    map<int, int> mp;
    multiset<int> s;
    StockPrice() {}
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end())
        {
            auto it = s.find(mp[timestamp]);
            s.erase(it);
        }
        mp[timestamp] = price;
        s.insert(price);
    }
    int current() {
        auto it = mp.end(); it--;
        return it->second;
    }
    int maximum() { auto it = s.end(); it--; return *it; }
    int minimum() { return *s.begin(); }
};
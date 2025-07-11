class RandomizedCollection
{
public:
    unordered_map<int, set<int>> mp;
    vector<int> v;

    RandomizedCollection() {}
    
    bool insert(int val)
    {
        bool was = true;
        if(mp.find(val) != mp.end()) was = false;
        mp[val].insert(v.size());
        v.push_back(val);
        return was;
    }
    
    bool remove(int val)
    {
        if(mp.find(val) != mp.end())
        {
            int index = *(--mp[val].end());
            mp[val].erase(--mp[val].end());
            if(mp[val].size() == 0) mp.erase(val);
            if(index == v.size() - 1) v.pop_back();
            else {
                v[index] = v.back();
                mp[v.back()].erase(v.size() - 1);
                mp[v.back()].insert(index);
                v.pop_back();
            }
            return true;
        }
        return false;
    }
    
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};
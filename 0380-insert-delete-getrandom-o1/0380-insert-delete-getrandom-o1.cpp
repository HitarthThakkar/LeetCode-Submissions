class RandomizedSet
{
public:
    vector<int> v;
    unordered_map<int, int> m;

    RandomizedSet() {}
    
    bool insert(int val)
    {
        if(m.find(val) == m.end())
        {
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool remove(int val)
    {
        if(m.find(val) == m.end())
        {
            return false;
        }
        else
        {
            int ind = m[val];
            v[ind] = v[v.size() - 1];
            m[v[ind]] = ind;
            v.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};
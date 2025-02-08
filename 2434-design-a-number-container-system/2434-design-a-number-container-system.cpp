class NumberContainers
{
public:
    unordered_map<int, int> iv;
    unordered_map<int, set<int>> vi;
    NumberContainers(){}
    void change(int index, int number)
    {
        if(iv.find(index) != iv.end())
        {
            int val = iv[index];
            vi[val].erase(index);
            if(vi[val].empty()) vi.erase(val);
        }
        iv[index] = number;
        vi[number].insert(index);
    }
    int find(int number)
    {
        if(vi.find(number) != vi.end()) return *(vi[number].begin());
        return -1;
    }
};
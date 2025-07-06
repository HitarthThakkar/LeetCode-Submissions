class FindSumPairs
{
public:
    map<int, int> m, m2;
    vector<int> v;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        v = nums2;
        for(auto e : nums1) m[e]++;
        for(auto e : nums2) m2[e]++;
    }
    
    void add(int index, int val)
    {
        int oldVal = v[index];
        v[index] += val;
        m2[oldVal]--;
        if(m2[oldVal] == 0) m2.erase(oldVal);
        m2[v[index]]++;
    }
    
    int count(int tot)
    {
        int answer = 0;
        if(m.size() < m2.size())
        {
            for(auto e : m)
            {
                int toFind = tot - e.first;
                if(m2.find(toFind) != m2.end())
                {
                    int f2 = m2[toFind];
                    answer += (e.second * f2);
                }
            }
        }
        else
        {
            for(auto e : m2)
            {
                int toFind = tot - e.first;
                if(m.find(toFind) != m.end())
                {
                    int f2 = m[toFind];
                    answer += (e.second * f2);
                }
            }
        }
        return answer;
    }
};
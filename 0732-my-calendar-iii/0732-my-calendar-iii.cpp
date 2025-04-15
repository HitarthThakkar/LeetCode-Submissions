class MyCalendarThree
{
public:
    map<int, int> m;
    int k = 1;
    MyCalendarThree() {}
    int book(int start, int end)
    {
        m[start]++;
        m[end]--;
        int current = 0;
        for(auto e : m) k = max(k, current += e.second);
        return k;
    }
};
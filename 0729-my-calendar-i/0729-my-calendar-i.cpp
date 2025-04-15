class MyCalendar
{
public:
    map<int, int> m;
    MyCalendar() {}
    bool book(int start, int end)
    {
        if(m.size() > 0)
        {
            auto it = m.lower_bound(start);
            if(it == m.end())
            {
                it--;
                if(it->second <= start)
                {
                    m.insert({start, end});
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if(end <= it->first)
            {
                if(it == m.begin())
                {
                    m.insert({start, end});
                    return true;
                }
                else
                {
                    it--;
                    if(it->second <= start)
                    {
                        m.insert({start, end});
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        m.insert({start, end});
        return true;
    }
};
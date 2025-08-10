class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string n_as_str = sorted_num_as_str(n);
        for (int i = 0; i < 30; i++)
            if (n_as_str == sorted_num_as_str(1 << i)) return true;
        return false;
    }
    
    string sorted_num_as_str(int n)
    {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
};
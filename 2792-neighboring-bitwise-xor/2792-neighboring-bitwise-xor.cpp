class Solution
{
public:
    bool doesValidArrayExist(vector<int>& derived)
    {
        int n = derived.size();
        int prev = 0;
        for(int i = 0; i < n; i++) if(derived[i]) prev = !prev;
        return (!prev);
    }
};
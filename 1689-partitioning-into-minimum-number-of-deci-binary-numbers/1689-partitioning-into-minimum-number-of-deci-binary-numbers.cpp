class Solution
{
public:
    int minPartitions(string n)
    {
        int mexDigit = 0;
        for(auto c : n) mexDigit = max(mexDigit, c - '0');
        return mexDigit;
    }
};
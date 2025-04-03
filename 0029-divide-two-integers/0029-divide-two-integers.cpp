class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool positive = true;
        if(dividend >= 0 && divisor < 0) positive = false;
        if(dividend <= 0 && divisor > 0) positive = false;
        long up = abs(1LL * dividend);
        long down = abs(1LL * divisor);
        long quotient = 0;
        while(up >= down)
        {
            int count = 0;
            while(up >= (down << (count + 1))) count++;
            quotient += (1 << count);
            up -= (down << count);
        }
        if(quotient == (1 << 31)) return (positive ? INT_MAX : INT_MIN);
        return (positive ? quotient : -quotient);
    }
};
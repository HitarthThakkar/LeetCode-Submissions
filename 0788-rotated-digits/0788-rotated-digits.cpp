class Solution
{
public:

    bool isValid(int n)
    {
        bool change = false;
        while(n)
        {
            int digit = n % 10;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) change = true;
            else if(digit != 0 && digit != 1 && digit != 8) return false;
            n /= 10;
        }
        return change;
    }

    int rotatedDigits(int n)
    {
        int res = 0;
        for(int i = 1; i <= n; i++) res += isValid(i);
        return res;
    }
};
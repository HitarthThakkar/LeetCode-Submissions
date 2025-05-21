class Solution
{
public:
    bool isUgly(int n)
    {
        if(n < 1) return false;
        while(n > 1)
        {
            bool gone = false;
            while(n % 2 == 0) n /= 2, gone = true;
            while(n % 3 == 0) n /= 3, gone = true;
            while(n % 5 == 0) n /= 5, gone = true;
            if(!gone) return false;
        }
        return true;
    }
};
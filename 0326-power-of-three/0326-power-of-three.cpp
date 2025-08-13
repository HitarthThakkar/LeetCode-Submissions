class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        int ld = (n % 10);
        if(ld != 3 && ld != 9 && ld != 7 && ld != 1) return false;
        if(n == 0) return false;
        if(n < 0) n *= -1;
        while(n > 1) {
            int ld = (n % 10);
            if(ld != 3 && ld != 9 && ld != 7 && ld != 1) return false;
            if(n % 3 == 0) n /= 3;
            else return false;
        }
        return true;
    }
};
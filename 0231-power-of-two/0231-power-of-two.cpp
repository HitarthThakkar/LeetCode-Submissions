class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ones = 0;
        while (n > 0)
        {
            if(n & 1)
            {
                ones++;
                if(ones > 1)
                {
                    return false;
                }
            }
            n = n / 2;
        }
        if(ones == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
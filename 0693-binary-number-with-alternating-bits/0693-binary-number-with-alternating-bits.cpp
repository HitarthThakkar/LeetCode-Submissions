class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int lb = -1;
        
        while(n) {
            if(n & 1) {
                if(lb == 1) return false;
                else lb = 1;
            }
            else {
                if(lb == 0) return false;
                else lb = 0;
            }

            n >>= 1;
        }

        return true;
    }
};
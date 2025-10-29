class Solution {
public:
    int smallestNumber(int n) {
        if(n == 1) return n;
        int x = 1;
        while(x <= n) {
            x <<= 1;
        }
        return (x - 1);
    }
};